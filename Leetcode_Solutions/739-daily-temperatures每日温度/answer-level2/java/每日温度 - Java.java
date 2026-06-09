### 解题思路：
第一种方法，从左到右遍历，这是最容易想到的办法。其原理是从左到右除了最后一个数其他所有的数都遍历一次，最后一个数据对应的结果肯定是 $0$，就不需要计算。遍历的时候，每个数都去向后数，直到找到比它大的数，这其他数了几次就是对应的值。

**实现的算法如下：**
```java [-Java]
public int[] dailyTemperatures(int[] T) {
    int length = T.length;
    int[] result = new int[length];

    for (int i = 0; i < length; i++) {
        int current = T[i];
        if (current < 100) {
            for (int j = i + 1; j < length; j++) {
                if (T[j] > current) {
                    result[i] = j - i;
                    break;
                }
            }
        }
    }

    return result;
}
```

还是那句话，这种很容易想到的笨办法，肯定不是我们想要的算法，那我们就需要找到更加快速的方法，在这道题中也就是要减少遍历的次数。

第二种方法，怎样减少遍历次数呢？我们可以分析，遍历一次数组中所有的值应该是少不了的，因为至少数组中每个值都需要计算一遍，所以时间复杂度肯定大于 $O(n)$。关键是要减少为每个数寻找值遍历次数。

如下图所示，绿色部分区域会给多次遍历，如果我们能减少这部分区域的遍历次数，就能整体提高运算效率。
![image.png](https://pic.leetcode-cn.com/63f890bd5ecec9b4a34d4cddf066643b14150f8714c10968d288902da231de07-image.png){:width=500}
{:align=center}


如果我们先从计算右边，那么我们计算过的位置就不需要重复计算，如图所示：

![image.png](https://pic.leetcode-cn.com/0f16daf6fde5475d72cbb6e9efec1d66409590141b861c2cf62fd87394211a82-image.png){:width=500}
{:align=center}

当前我们需要计算 $75$ 位置，然后向右遍历到 $71$，因为我们已经计算好了 $71$ 位置对应的值为 $2$，那么我们就可以直接跳 $2$ 为在进行比较，利用了已经有的结果，减少了遍历的次数。

**实现算法如下：**
```java [-Java]
public int[] dailyTemperatures(int[] T) {
    int length = T.length;
    int[] result = new int[length];

    //从右向左遍历
    for (int i = length - 2; i >= 0; i--) {
        // j+= result[j]是利用已经有的结果进行跳跃
        for (int j = i + 1; j < length; j+= result[j]) {
            if (T[j] > T[i]) {
                result[i] = j - i;
                break;
            } else if (result[j] == 0) { //遇到0表示后面不会有更大的值，那当然当前值就应该也为0
                result[i] = 0;
                break;
            }
        }
    }

    return result;
}
```

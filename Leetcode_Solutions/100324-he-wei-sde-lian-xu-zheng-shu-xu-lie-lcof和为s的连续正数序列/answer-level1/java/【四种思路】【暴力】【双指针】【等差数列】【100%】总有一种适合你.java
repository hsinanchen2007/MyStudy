### 思路一：

暴力

### 代码：

```
class Solution {
    public int[][] findContinuousSequence(int target) {
        List<int []> res = new ArrayList<>();
        if(target < 3)
            return res.toArray(new int[0][]);

        for(int i = 1; i <= target / 2 + 1; i++){
            int temp_sum = i;
            for(int j = i + 1; j <= target / 2 + 1; j++){
                temp_sum += j;
                if(temp_sum == target){
                    int count = 0;
                    int [] temp = new int [j - i + 1];
                    for(int k = i; k <= j; k++)
                        temp[count++] = k;
                    res.add(temp);
                } else if(temp_sum > target)
                    break;
            }
        }
        return res.toArray(new int[0][]);
    }
}
```
### Result：

Runtime：10ms

Your runtime beats 31.57% of java submissions.

### 思路二：

有点双指针的感觉。。（滑动窗口）

其实在找第一组满足条件的序列时，已经计算了部分和，并不需要重新算了。只需要用当前和减去上个序列的最小值即为下个待求序列的和，再从 high++ 即可。

low 指针标志序列的起点，high 指针标志序列的终点。

![image](https://pic.leetcode-cn.com/af4821c41d5b093e6a41ad5602208f9e7057cc1b002cd0053de71bc9a0e35b12.jpg)

至于为什么是 (target + 1) / 2

```
因为 (target/2 + (target+1)/2) > target
```

### 代码：

```java
class Solution {
    public int[][] findContinuousSequence(int target) {
        List<int []> res = new ArrayList<>();
        if(target < 3)
            return res.toArray(new int[0][]);
        int low = 1, high = 2;
        int temp_sum = 3;
        for(; low <= target / 2 + 1; low++){
            while(temp_sum < target){
                high ++;
                temp_sum += high;
            }
            if(temp_sum == target){
                int i = 0;
                int [] temp = new int [high - low + 1];
                for(int k = low; k <= high; k++)
                    temp[i++] = k;
                res.add(temp);
            }
            temp_sum -= low;
        }
        return res.toArray(new int[0][]);
    }
}
```

### Result：

Runtime：5ms

Your runtime beats 67.35% of java submissions.

### 思路三：

数学推导（等差数列）

1）由于我们要找的是和为S的连续正数序列，因此这个序列是个公差为1的等差数列，**而这个序列的中间值代表了平均值的大小**。假设序列长度为n，那么这个序列的中间值可以通过（S / n）得到，知道序列的中间值和长度，也就不难求出这段序列了。

2）满足条件的n分两种情况：

**n为奇数时**，序列中间的数正好是序列的平均值，所以条件为：(n & 1) == 1 && sum % n == 0；

**n为偶数时**，序列中间两个数的平均值是序列的平均值，而这个平均值的小数部分为0.5，所以条件为：(sum % n) * 2 == n.

3）由题可知n >=2，那么n的最大值是多少呢？我们完全可以将n从2到S全部遍历一次，但是大部分遍历是不必要的。为了让n尽可能大，我们让序列从1开始，根据等差数列的求和公式：S = (1 + n) * n / 2，得到n最大为sqrt(2*sum)

最后举一个例子，假设输入sum = 100，我们只需遍历n = 13~2的情况（按题意应从大到小遍历），n = 8时，得到序列[9, 10, 11, 12, 13, 14, 15, 16]；n = 5时，得到序列[18, 19, 20, 21, 22]。

### 代码：

```java
class Solution {
    public int[][] findContinuousSequence(int target) {
        List<int []> res = new ArrayList<>();
        if(target < 3)
            return res.toArray(new int[0][]);

        for(int n = (int)Math.sqrt(2 * target); n >= 2; n--){
            if((n & 1) == 1 && target % n == 0 || (target % n) * 2 == n){
                int [] temp = new int [n];
                for(int j = 0, k = (target / n) - (n - 1)/2; j < n; j++, k++)
                    temp[j] = k;
                res.add(temp);
            }
        }
        return res.toArray(new int[0][]);
    }
}
```

### Result：

Runtime：0ms

Your runtime beats 100% of java submissions.

### 思路四：

还是数学推导（等差数列）

### 代码：

```java
class Solution {
    public int[][] findContinuousSequence(int target) {
        List<int []> res = new ArrayList<>();
        if(target < 3)
            return res.toArray(new int[0][]);

        for (int i = 2; i < target + 1; i++) {
            int temp = target - i * (i - 1) / 2;
            if (temp <= 0) {
                break;
            }
            if (temp % i == 0) {
                int a_1 = temp / i;
                int arr [] = new int [i];
                for (int j = 0; j < i; j++) {
                    arr[j] = j + a_1;
                }
                res.add(arr);
            }
        }
        Collections.reverse(res);
        return res.toArray(new int[0][]);
    }
}
```

### Result：

Runtime：0ms

Your runtime beats 100% of java submissions.
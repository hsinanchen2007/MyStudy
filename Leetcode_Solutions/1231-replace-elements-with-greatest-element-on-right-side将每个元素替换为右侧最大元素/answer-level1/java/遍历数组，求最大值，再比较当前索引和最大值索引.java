### 解题思路
1. 遍历数组
2. 第i 个数，找到右边最大的元素maxIndex，并记录下索引值maxIndex，说明 [i, maxIndex) 这个区间右边最大元素都是maxIndex
3. 下一个元素，如果i < maxIndex,arr[i]直接赋值最大元素maxValue，否则回到第二步
![image.png](https://pic.leetcode-cn.com/5cfe778398f86e6c698ae9875e57cc82bfe32cb2032ac9b4b957a41175773bb2-image.png)


### 代码

```java
class Solution {
    public int[] replaceElements(int[] arr) {
        int maxIndex = -1;
        int maxValue;
        for (int i = 0; i < arr.length; i++) {
            if (i < maxIndex) {
                arr[i] = arr[maxIndex];
                continue;
            }
            maxValue = -1;
            for (int j = i + 1; j < arr.length; j++) {
                if (arr[j] > maxValue) {
                    maxValue = arr[j];
                    maxIndex = j;
                }
            }
            arr[i] = maxValue;
        }
        return arr;
    }
}
```
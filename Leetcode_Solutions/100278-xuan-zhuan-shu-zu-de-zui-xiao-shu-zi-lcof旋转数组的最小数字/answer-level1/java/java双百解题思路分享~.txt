### 解题思路
看了很多大神的二分思想，我也想分享一下我的解题思路。
![image.png](https://pic.leetcode-cn.com/b81d559706e3b085606ae9f5da10497d1a198d8b07f3ae70c4f90c9dd499530a-image.png)
时间复杂度：O(n)
分析：
    1. 该数组在旋转前是一个递增数组，所以最小值肯定是第一个数。旋转后，这个数组就被分成了两个递增数列，而分界点就是这个数组的最小值，问题转换成找分界点的问题。
    2. 那么如何去寻找分界点呢？我这里直接令最小值（min）是旋转数组索引为0的数值，然后遍历整个数组，一旦发现有一个值比min小，那么这个值就是整个数组的最小值。
欢迎大神们拍砖指出问题和提意见~互相交流学习~

### 代码

```java
class Solution {
    public int minArray(int[] numbers) {
        if (numbers.length==0) return 0;
        int min = numbers[0];
        for (int i=1; i<numbers.length; i++) {
            if (numbers[i]<min) {
                min = numbers[i];
                break;
            }
        }
        return min;
    }
}
```
### 解题思路
![image.png](https://pic.leetcode-cn.com/e80532c1f80a91ef4c3c0493be1811ff12caba3efe7d683c4ce92647301017c4-image.png)

第一次写题解，望大佬们指正


### 代码

```java
class Solution {
    public boolean canThreePartsEqualSum(int[] A) {
        if (A.length < 3) {
            return false;
        }
        // 求和
        int totalSum = 0;
        for (int n : A) {
            totalSum += n;
        }
        // 如果不是3的倍数则必然不成立
        if (totalSum % 3 != 0) {
            return false;
        }

        int target = totalSum / 3;
        int subSum = 0;
        // 记录次数
        int count = 0;
        // 最后一位不遍历，如果前面n-1个数里找到了两组，则剩下的必然是第3组
        for (int i = 0; i < A.length - 1; i++) {
            subSum += A[i];
            if (subSum == target) {
                count++;
                if (count == 2) {
                    return true;
                }
                subSum = 0;
            }
        }
        return false;
    }
}
```
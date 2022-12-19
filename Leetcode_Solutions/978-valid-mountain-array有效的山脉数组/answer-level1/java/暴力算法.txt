解题思路：首先小于等于3 返回false 。然后一个个遍历，判断，确保出现次A[i]<A[i-1]后代表已经出现了最高点，后面只要出现A[i]>A[i-1] 直接返回false。

```java []
public boolean validMountainArray(int[] A) {
        if (A.length < 3) {
            return false;
        }
//  防止 987654 这总
        if (A[0] >= A[1]) {
            return false;
        }
        boolean hasMountain = false;
        for (int i = 1; i < A.length; i++) {
//只要出现 前后相等就一定是错的 后面不用考虑 大于还是大于等于了 比较简单
            if (A[i] == A[i - 1]) {
                return false;
            }
            if (hasMountain && A[i] > A[i - 1]) {
                return false;
            }
            if (A[i] < A[i - 1]) {
                hasMountain = true;
            }
        }
        return hasMountain ;
    }
```
* 时间复杂度:O(n)
* 空间复杂度:O(1)

### 解题思路
分成偶数,奇数数组
分别从奇，偶数组取值构造结果

### 代码

```java
class Solution {
    public int[] sortArrayByParityII(int[] A) {
        int n = A.length;
        int[] odd = new int[n / 2];  // 奇数
        int[] even = new int[n / 2]; // 偶数
        int j = 0, k = 0;
        for (int i = 0; i < n; i++) {
            if (A[i] % 2 == 0) {
                even[j++] = A[i];
            } else {
                odd[k++] = A[i];
            }
        }
        int result[] = new int[n];
        int m = 0, y = 0;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                result[i] = even[m++];
            } else {
                result[i] = odd[y++];
            }
        }
        return result;
    }
}
```
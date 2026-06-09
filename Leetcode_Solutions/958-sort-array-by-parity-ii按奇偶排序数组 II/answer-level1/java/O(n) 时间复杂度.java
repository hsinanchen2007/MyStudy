### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] sortArrayByParityII(int[] A) {
        int [] ans = new int [A.length];
        int index1 = 0;
        int index2 = 1;
        for (int i = 0; i < A.length; i++) {
            if (A[i] % 2 == 0) {
                ans[index1] = A[i];
                index1 += 2;
            }else {
                ans[index2] = A[i];
                index2 += 2;
            }
        }
        return ans;
    }
}
```
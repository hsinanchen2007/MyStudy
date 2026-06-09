### 解题思路
双指针，简单易懂

### 代码

```java
class Solution {
    public int[] sortArrayByParityII(int[] A) {
        int even = 0;
        int odd = 1;
        int[] res = new int[A.length];
        for (int i = 0; i < A.length; i++){
            if ((A[i] & 1) == 0){
                // 是偶数
                res[even] = A[i];
                even += 2;
            } else {
                res[odd] = A[i];
                odd += 2;
            }
        }
        return res;
    }
}
```
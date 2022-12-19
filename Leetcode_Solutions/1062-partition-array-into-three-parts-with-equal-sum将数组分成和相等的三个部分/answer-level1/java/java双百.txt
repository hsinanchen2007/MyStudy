### 解题思路
两次遍历，第一次遍历求出数组总和，要不是3的倍数直接false，然后第二次遍历，使得各部分等于总和/3.对于总和为0的情况，这样的部分可能会很多，例如[10,-10,10,-10,10,-10,10,-10],返回这样的部分数目>=3即可

### 代码

```java
class Solution {
    public boolean canThreePartsEqualSum(int[] A) {
        int l = A.length;
        int s = 0;
        for (int i = 0; i < l; i++){
            s += A[i];
        }
        if (s % 3 != 0){
            return false;
        } else{
            s = s / 3;
            int temp = 0;
            int res = 0;
            for (int i = 0; i < l; i++){
                temp += A[i];
                if (temp == s){
                    temp = 0;
                    res++;
                }
            }
            return res >= 3;
        }
    }
}
```
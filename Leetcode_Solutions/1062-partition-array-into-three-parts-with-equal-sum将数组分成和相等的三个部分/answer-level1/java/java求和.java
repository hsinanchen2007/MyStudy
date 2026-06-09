执行用时 :1 ms, 在所有 Java 提交中击败了100.00%的用户
内存消耗 :44.4 MB, 在所有 Java 提交中击败了100.00%的用户

好像有点点暴力。。。

```
代码块
class Solution {
    public boolean canThreePartsEqualSum(int[] A) {
        int total = 0;
        for(int i=0; i<A.length;i++) {
            total += A[i];
        }
        if(total % 3 != 0) {
            return false;
        }
        int num = total / 3;
        int he = 0;
        int result = 1;
        for(int i=0; i<A.length; i++) {
            he += A[i];
            if(he == num * result) {
                if(result == 4){
                    break;
                }
                result++;
            }
            
        }
        return result == 4;
    }
}
```

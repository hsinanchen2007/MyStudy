### 解题思路
分别判断A和B是否包含0，不包含则加入数组输出，否则继续递归。

### 代码

```java
class Solution {
    public int[] getNoZeroIntegers(int n) {
        int[] ans = new int[2];
        for(int i = 1;i < n; i++){
            int A = i , B = n - i;
            if(containsZero(A) && containsZero(B)){
                ans[0] = A;
                ans[1] = B;
                break;
            }
        }
        return ans;        
    }
    private boolean containsZero(int x){
        while(x > 0){
            if(x%10 == 0){
                return false;
            }
            x -= x%10;
            x /=10;
        }
        return true;
    }
}
```
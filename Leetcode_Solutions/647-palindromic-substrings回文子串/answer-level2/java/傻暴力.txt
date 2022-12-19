### 解题思路
傻暴力
### 代码

```java
class Solution {
    private boolean IsOK(String s,int i0,int j0){
        boolean Ok=true;
        for(int i=i0,j=j0;i<=j;i++,j--){
            if(s.charAt(i)!=s.charAt(j)) {
                Ok=false;
                break;
            }
        }
        return Ok;
    }
    public int countSubstrings(String s) {
        int sum=0;
        for(int i=0;i<s.length();i++){
            for(int j=0;i-j>=0;j++){
                if(IsOK(s,i-j,i))
                    sum++;
            }
        }
        return sum;
    }
}
```
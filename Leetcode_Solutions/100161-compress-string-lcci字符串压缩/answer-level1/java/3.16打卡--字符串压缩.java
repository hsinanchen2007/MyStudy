### 解题思路
比较简单的思路

### 代码

```java
class Solution {
    public String compressString(String S) {
        if(S == null || S.length()<=2){
            return S;
        }
        StringBuilder sb = new StringBuilder().append(S.charAt(0));
        int cnt = 1;
        for(int i = 1 ; i < S.length() ; i++){
            if(S.charAt(i) == S.charAt(i-1)){
                cnt++;
            }else{
                sb.append(cnt).append(S.charAt(i));
                cnt = 1;
            }
        }
        return sb.append(cnt).length()<S.length() ? sb.toString() : S;
    }
}
```
### 解题思路
String builder快一点

### 代码

```java
class Solution {
    public String compressString(String S) {
        
        if(S.length() == 0){
            return S;
        }
        char  tmp = S.charAt(0);
        int cnt = 0;
        StringBuilder result = new StringBuilder();
        for(int i = 0;i<S.length();i++){
            if(tmp != S.charAt(i)){
                result.append(tmp);
                result.append(cnt);
                cnt = 1;
                tmp = S.charAt(i);
            }else{
                cnt++;
            }
        }
        result.append(tmp);
        result.append(cnt);
        if(result.length()<S.length()){
            return result.toString();
        }else{
            return S;
        }

    }
}
```
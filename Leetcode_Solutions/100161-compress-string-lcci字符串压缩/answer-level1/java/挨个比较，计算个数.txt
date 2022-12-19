### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String compressString(String S) {
        int len = S.length();
        if(S == null || len == 0){
            return S;
        }
        char target = S.charAt(0);
        int cnt = 1;
        StringBuilder sb = new StringBuilder();
        sb.append(target);
        for(int i = 1; i < len; i++){
            if(S.charAt(i) != target){
                sb.append(cnt);
                target = S.charAt(i);
                sb.append(target);
                cnt = 1;
            }else{
                cnt++;
            }
        }
        sb.append(cnt);
        if(sb.length() >= len){
            return S;
        }else{
            return sb.toString();
        }
    }
}
```
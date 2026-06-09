### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String compressString(String S) {
        if(S.length()<=2)
            return S;
        StringBuilder sb = new StringBuilder();
        sb.append(S.charAt(0));
        int l=0,r=1;
        int count = 1;
        while(r<S.length()){
            if(S.charAt(l)==S.charAt(r))
                count++;
            else{
                l = r;
                sb.append(count);
                sb.append(S.charAt(r));
                count = 1;
            }
            r++;
            
        }
        sb.append(count);
        return sb.length()<S.length()?sb.toString():S;
    }
}
```
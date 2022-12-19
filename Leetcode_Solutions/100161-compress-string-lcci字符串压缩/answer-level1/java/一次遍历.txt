### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String compressString(String S) {
        if(S.length()==0) return "";
        int i = 0;
        int j = 1;
        StringBuffer a = new StringBuffer();
        char[] s = S.toCharArray();
        while(i<j&&j<S.length()){
            // if(j)
            if(s[i]!=s[j]){
                a.append(String.valueOf(s[i])+String.valueOf(j-i));
                i = j;
                j++;
            }else{
                j++;
            }
        }
        a.append(String.valueOf(s[i])+String.valueOf(j-i));
        if(S.length()>a.length()){
            return a.toString();
        }else{
            return S;
        }
        
    }
}
```
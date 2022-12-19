### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String compressString(String S) {
        if(S.length() <= 2|| S == null){
            return S;
        }
        StringBuilder afterCompressString = new StringBuilder().append(S.charAt(0));
        int count = 1;
        for(int i =1;i < S.length();i++){
            if(S.charAt(i) == S.charAt(i-1)){
                count++; 
            }
            else 
            {
                afterCompressString.append(count).append(S.charAt(i));
                count = 1;
            }
        }
        return afterCompressString.append(count).length() < S.length() ? afterCompressString.toString() : S;

    }
}
```
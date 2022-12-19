### 解题思路
第一个字母是大写的时候，就从第二个字母开始往后判断。
第一个字母是小写的时候，就从第一个字母开始往后判断。

### 代码

```java
class Solution {
    /*
        65~90 是A~Z
        97~122 是a~z
    
    */
    public boolean detectCapitalUse(String word) {
        if(word.length() == 0 || word.length() == 1)    
            return true;
        
        int big = 0; // 1表示大写，0表示小写

        char[] chars = word.toCharArray();
        if(chars[0] > 64 && chars[0] < 91){
            if(chars[1] > 64 && chars[1] < 91)
                big = 1;
            else if(chars[0] > 96 && chars[0] < 123)
                big = 0;
        }
        else if(chars[0] > 96 && chars[0] < 123)
            big = 0;
        else
            return false;

        for(int i = 1; i < chars.length; i++){
            if(big == 1){
                if(chars[i] > 64 && chars[i] < 91){
                    continue;
                }
                else
                    return false;
            }
            else{
                if(chars[i] > 96 && chars[i] < 123){
                    continue;
                }
                else
                    return false;
            }
        }
        return true;
    }
}
```
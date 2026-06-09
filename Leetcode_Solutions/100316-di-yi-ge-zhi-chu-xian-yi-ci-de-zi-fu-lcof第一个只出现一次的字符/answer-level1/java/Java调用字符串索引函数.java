### 解题思路
暴力破万法,直接调用函数判断从头部开始第一次出现的位置以及从尾部开始第一次出现的位置是否一致

### 代码

```java
class Solution {
    public char firstUniqChar(String s) {

        for(int i = 0; i < s.trim().length(); i++){
            char c = s.charAt(i);
            if(s.indexOf(c) == i && s.lastIndexOf(c) == i){
                return c;
            }
        }

        return ' ';
        
    }
}
```
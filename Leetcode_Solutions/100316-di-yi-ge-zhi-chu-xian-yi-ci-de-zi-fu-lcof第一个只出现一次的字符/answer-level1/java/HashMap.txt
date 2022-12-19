### 解题思路
1.HashMap方法
先第一遍扫描得出{key：value}
2.对hashmap进行扫描，当value==1时，返回key值
### 代码

```java
class Solution {
    public char firstUniqChar(String s) {
        //HashMap先扫描一遍
        HashMap<Character,Integer> char_count = new HashMap<>();
        int len = s.length();
        // char res = ' ';
        for(int i = 0;i < len; i++){
        
            char c = s.charAt(i);
            if(char_count.containsKey(c)){
                char_count.put(c,char_count.get(c)+1);
            }
            else{
                char_count.put(c,1);
            }
        }
        
        //pop出第一个value=1的key
        for(int i = 0; i < len;i++){
            char c = s.charAt(i);
            if(char_count.get(c) == 1) return c;
        }

        return ' ';

    }
}
```
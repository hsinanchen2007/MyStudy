### 解题思路
因为要计算出现次数 所以考虑map
### 代码

```java
class Solution {
    public char firstUniqChar(String s) {
        int len = s.length();  //算出字符串的长度
        char c1 = ' ';         //空串
        Map<Character,Integer> map = new HashMap<>(); 
        int count = 1;         //计数用
       for(int i=0;i<len;i++){  //遍历字符串
           if(map.containsKey(s.charAt(i))){  //map中已包含当前字符
               map.put(s.charAt(i),++count); //将当前字符放入map中 value递增
           }else{               //map中不包含当前字符
               count = 1;       
               map.put(s.charAt(i),count);  // //将当前字符放入map中 value=1
           }
       }
       for(int i=0;i<len;i++){   //遍历字符串
           char c = s.charAt(i);  //获取当前位置字符
           if(map.get(c) == 1){  //如果字符出现次数为1
               return c;        //返回该字符
           }
       }
        return c1;              //否则返回空
    }
}
```
### 解题思路
此处撰写解题思路
拷贝于画解算法

### 代码

```java
class Solution {
    public int lengthOfLongestSubstring(String s) {
       int length=0;//起初为0
       Map<Character, Integer> map=new HashMap<>();
       for(int start=0,end=0;end<s.length();end++){
           char alpha=s.charAt(end);
           if(map.containsKey(alpha)){//如果遇到重复字母，更新start
               start=Math.max(map.get(alpha),start);//防止start左移
           }
           length=Math.max(length,end-start+1);
           map.put(s.charAt(end),end+1);//加入遍历的字符
       }
       return length;
    }
    
}


```
### 解题思路
回文字成立条件：
1、各字符成双出现
2、最多只有一个落单字符，其余各字符成双出现
解题思路：
把字符串拆开成一个一个往set集合中添加，利用set的元素不重复性把成双出现的字符从集合中排除掉
最后剩下落单字符被留在set集合中，如果落单字符数超过一个，则不是回文字符串
### 代码

```java
class Solution {
    public boolean canPermutePalindrome(String s) {
        
        //利用set集合的不重复性
        Set<Character> set =  new HashSet<>();
        for (char c : s.toCharArray()){
            if (!set.add(c)){//当往set中添加重复的字符时，添加失败，返回false
                set.remove(c);
            }
        }
        return set.size()<=1;    
    }
}
```
运用LinkedList链表的特性，**非常巧妙**的解法。

1. Hash Table存储数字和其对应的字符数组。
2. 遍历字符串，获取数字，如果列表数组ls的头部元素（peek()或者element()方法）的长度和数组下标一致，表示还未加入组合数字。例如，digits="23",当ls是a->b->c,i=1时，ls的头部元素a的长度是1，还需要加入3对应的字符数组d,e,f,将头部元素移出(remove()或poll()方法)到临时字符串temp，遍历字符数组d，e，f，temp逐个和他们相加后add到ls数组中。
3. 代码如下：
```java
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
//运用LinkedList的一种巧妙解法
class Solution {
    public List<String> letterCombinations(String digits) {
        LinkedList<String> ls = new LinkedList<String>();
        if(digits.length()==0)
            return ls;
        HashMap<Integer,char[]> map = new HashMap<>();
        map.put(2,new char[]{'a','b','c'});
        map.put(3,new char[]{'d','e','f'});
        map.put(4,new char[]{'g','h','i'});
        map.put(5,new char[]{'j','k','l'});
        map.put(6,new char[]{'m','n','o'});
        map.put(7,new char[]{'p','q','r','s'});
        map.put(8,new char[]{'t','u','v'});
        map.put(9,new char[]{'w','x','y','z'});

        char[] arr = digits.toCharArray();
        ls.add("");
        for(int i =0;i<arr.length;i++) {
            int x = arr[i]-'0';
            while (ls.peek().length()==i){
                String t = ls.poll();
                char[] temp = map.get(x);
                for(char c:temp)
                    ls.add(t+c);
            }
        }
        return ls;
    }

}
```

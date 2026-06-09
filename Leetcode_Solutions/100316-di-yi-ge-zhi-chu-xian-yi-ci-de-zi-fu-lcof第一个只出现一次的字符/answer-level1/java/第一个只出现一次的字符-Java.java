### 解题思路
Java集合中的Map，是双列集合，键值对存储方式。因此可以利用键存储字符，值存储对应出现次数。
但是Map集合是一个接口，不能创建实例，只能通过其实现类来创建对象HashMap<>()。
对传入的参数s获取单个字符charAt(i)，得到单个字符后判断是否已经存在于map中，如果不在，说明是遍历中的第一次遇到，将其添加到map，并设置值为1，之后的遍历若再遇到第二次，重新调用put，但此时为更新键值对并非重新添加，即键不变，值改变。

### 代码

```java
class Solution {
    public char firstUniqChar(String s) {
        if(s.isEmpty()) return ' ';
        
        int len = s.length();
        Map<Character,Integer> map = new LinkedHashMap<>();
        char c;
        for(int i = 0;i < len;i++){
            c = s.charAt(i);
            if(map.containsKey(c))
                map.put(c,map.get(c)+1);
            
            else
                map.put(c,1);
            
            
        }
        for(int i = 0;i < len;i++){
            c = s.charAt(i);
            if(map.get(c) == 1)
                return c;
        }
        return ' ';
    }
}
```
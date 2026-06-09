### 解题思路
题意指出，不常见单词为：在一个句子中只出现一次，在另一个句子中不出现。
因此，两个句子中都出现过的不算，同理，在一个句子中不出现，但在另一个句子中出现两次及以上的也不算。
综上，重复的都不算，即总出现次数为1的才是不常见单词。
利用map遍历两个句子，记录所有单词到其出现次数的映射，最后遍历map，返回出现次数为1的单词即可。

时间复杂度：O(n)。n为两个句子的长度之和。
空间复杂度：O(n)。

### 代码

```java
class Solution {
    public String[] uncommonFromSentences(String A, String B) {
        Map<String, Integer> map = new HashMap<String, Integer>();
        for(String s : A.split("\\s"))
            map.put(s, map.getOrDefault(s, 0) + 1);
        for(String s : B.split("\\s"))
            map.put(s, map.getOrDefault(s, 0) + 1);
        List<String> list = new LinkedList<String>();
        for(Map.Entry<String, Integer> entry : map.entrySet())
            if(entry.getValue() == 1)
                list.add(entry.getKey());
        return list.toArray(new String[list.size()]);
    }
}
```
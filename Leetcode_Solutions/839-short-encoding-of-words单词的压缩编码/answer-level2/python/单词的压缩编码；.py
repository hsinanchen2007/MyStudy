### 解题思路
遍历字符串集合，将包含的字符串去掉；最后统计集合中剩下的字符串的单词的长度并加上相应的#个数。

### 代码

```java []
class Solution {
    public int minimumLengthEncoding(String[] words) {
        int count = 0;
        Set<String> set = new HashSet<>();
        int length = words.length;
        for (int i = 0; i < length; i++) {
            set.add(words[i]);
        }
        for (String elem : words) {
            for (int i = 1; i < elem.length(); i++) {
                set.remove(elem.substring(i));
            }
        }
        for (String elem : set) {
            count += elem.length()+1;
        }
        return count;
    }
}
```
```python []
class Solution:
    def minimumLengthEncoding(self, words: List[str]) -> int:
        newset = set(words)
        count = 0
        for elem in words:
            for i in range(1, len(elem)):
                newset.discard(elem[i:]) 
        for elem in newset:
            count += len(elem) + 1
        return count
```
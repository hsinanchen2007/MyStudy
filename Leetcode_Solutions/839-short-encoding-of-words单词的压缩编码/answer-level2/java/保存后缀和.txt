### 解题思路
参考leetcode题解思路

### 代码

```java
class Solution {
    public int minimumLengthEncoding(String[] words) {
        //特例
        if (words.length < 1) {
            return words.length;
        }

        //使用set集合 保存单词后缀
        Set<String> set = new HashSet<>(Arrays.asList(words));

        for (String word : words) {
            for (int i = 1; i < word.length(); i++) {
                set.remove(word.substring(i));
            }
        }

        int count = 0;
        //统计数量
        for (String word : set) {
            count += word.length() + 1;
        }

        return count;
    }
}
```
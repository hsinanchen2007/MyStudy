### 解题思路
通过判断每一个单词是否是另一个单词的后缀，如果是则移除
1.首先移除一样的，选择用Set处理
2.然后判断每个单词的字串，从长到短判断
 重复的全部移除后，开始计算总的长度，记得每个单词后面有个#，其长度要加1

### 代码

```java
class Solution {
    public int minimumLengthEncoding(String[] words) {
        //首先字符串去重
        Set<String> wordsSet = new HashSet<String>(Arrays.asList(words));
        String rmWord;
        for (String word : words) {
            for (int i = 1; i < word.length(); i++) {
                rmWord = word.substring(i);
                if (wordsSet.contains(rmWord)) {
                    wordsSet.remove(rmWord);
                }
            }
        }

        int minLength = 0;
        for (String word : wordsSet) {
            minLength = minLength + word.length() + 1;
        }

        return minLength;
    }
}
```
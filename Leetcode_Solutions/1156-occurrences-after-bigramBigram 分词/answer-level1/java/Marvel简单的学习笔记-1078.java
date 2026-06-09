### 解题思路
遍历text的每个单词进行比较即可，找到紧随first的second，然后添加second后面的third。

### 代码

```java
class Solution {
    public String[] findOcurrences(String text, String first, String second) {
        String[] word = text.split("\\s");
        List<String> list = new ArrayList<String>();
        for(int i = 0; i < word.length-2; i++)
            if(word[i].equals(first) && word[i + 1].equals(second))
                list.add(word[i + 2]);
        return list.toArray(new String[list.size()]);
    }
}
```
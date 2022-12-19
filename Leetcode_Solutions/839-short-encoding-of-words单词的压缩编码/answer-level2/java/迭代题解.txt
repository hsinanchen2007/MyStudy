### 解题思路
单词之间只有尾部包含关系，才能压缩在一起，所以按照这个思路，迭代数组，筛选出相对应的单词即可

### 代码

```java
class Solution {
    public int minimumLengthEncoding(String[] words) {
        List<String> resultList = new LinkedList<String>();
        for (int i=0; i<words.length; ++i) {
            boolean add = true;
            if (!"-1".equals(words[i])) {
                for (int j = i + 1; j < words.length; ++j) {
                    if (!"-1".equals(words[j])) {
                        if (words[i].endsWith(words[j])) {
                            words[j] = "-1";
                        } else if (words[j].endsWith(words[i])) {
                            add = false;
                        }
                    }
                }
            } else {
                add = false;
            }
            
            if (add) {
                resultList.add(words[i]);
            }

            
        }
        int sum = resultList.size();
            for (String word : resultList) {
                sum += word.length();
            }

        return sum;
    }
}
```
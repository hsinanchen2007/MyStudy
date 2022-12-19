### 解题思路
本题采用双哈希表思路，一个记录单词，一个记录**不同单词**的缩写次数。

题目的关键词：**单词缩写是针对不同单词的**

上面的描述有一点不好理解，单词缩写的不同，针对的是不同单词；而相同的单词缩写是同一种，一模一样。有点绕，具体按下面几种情况说下：

1. 单词如果在字典中**重复**，这两个单词是**同一个单词**，依旧属于唯一的缩写。
2. 单词如果在字典中**没有重复**，这就是**不同单词**，单词缩写如果在哈希表中存在，则其不同单词缩写次数+1。

下面说下isUnique的判断标准：

1. 如果word**在字典中**，则其缩写次数是0，才表示字典中没有相同的单词缩写。
2. 如果word**不在字典中**，则其缩写次数是1，才表示单词在字典中缩写唯一，即字典中没有其他单词缩写和自己一样。

所以，用一个哈希表来存放**所有的单词**，另一个哈希表来记录**不同的单词和其出现的缩写次数**。

### 代码

```java
public class ValidWordAbbr {
    // 所有单词字典
    private Set<String> dict = new HashSet<>();
    // key ： 不同单词缩写格式 value : 不同单词缩写相同数目
    private Map<String,Integer> wordAbbrMap = new HashMap<>();

    public ValidWordAbbr(String[] dictionary) {
        StringBuilder str = new StringBuilder();
        for (int i = 0; i < dictionary.length; i++) {
            // 单词加入字典
            // 题目有个隐晦的条件，单词缩写出现的的次数，和本身单词不同的记录，即两个一样的单词，是同一个单词缩写，才是不同的次数
            if (!dict.add(dictionary[i])){
                continue;// 字典已经包含了，不需要再记录缩写了
            }
            // 单词缩写是针对不同单词的，这点是关键
            // 记录单词缩写
            int length = dictionary[i].length();
            if (length <= 2){
                str.append(dictionary[i]);
            } else {
                int size = length - 2;
                str.append(dictionary[i].charAt(0)) ;
                str.append(size);
                str.append(dictionary[i].charAt(length - 1));
            }
            wordAbbrMap.put(str.toString(),wordAbbrMap.getOrDefault(str.toString(),0) + 1);
            str.setLength(0);
        }
    }

    public boolean isUnique(String word) {
        // 单词是否存在
        boolean isExist = dict.contains(word);
        // 查找单词缩写
        StringBuilder str = new StringBuilder();
        int length = word.length();
        if (length <= 2){
            str.append(word);
        } else {
            int size = length - 2;
            str.append(word.charAt(0)) ;
            str.append(size);
            str.append(word.charAt(length - 1));
        }
        int count = wordAbbrMap.getOrDefault(str.toString(),0);
        // 字典中存在的，出现1次，字典中不存在，出现0次
        return  isExist ? count == 1 : count == 0;
    }
}



/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr obj = new ValidWordAbbr(dictionary);
 * boolean param_1 = obj.isUnique(word);
 */
```
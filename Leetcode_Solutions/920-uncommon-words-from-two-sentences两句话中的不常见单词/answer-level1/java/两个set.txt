### 解题思路

看似两句话，看完题目，还是一句话。。。一句话中只出现一次的单词。。。

使用两个set....
一个set放所有结果
一个set放出现1次的。

如果当前所有结果的Set已经存在了，就从1次的set中移除，无所谓是否已经移除过了。。。保证1次的Set中没有即可。

如果当前所有结果的Set不存在，结果放入两个set中。

### 代码

```java
class Solution {
    public String[] uncommonFromSentences(String A, String B) {
        String[] strs=(A+" "+B).split(" ");
        Set<String> str=new HashSet<>();
        Set<String> set=new HashSet<>();
        for (int i = 0; i < strs.length; i++) {
            if(str.contains(strs[i])){
                set.remove(strs[i]);
            }else{
                set.add(strs[i]);
            }
            str.add(strs[i]);
        }
        return set.toArray(new String[0]);
    }
}
```
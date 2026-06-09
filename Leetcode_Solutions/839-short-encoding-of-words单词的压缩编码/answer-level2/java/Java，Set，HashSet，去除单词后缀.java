### 解题思路
这道题我用去后缀思路：
  先用Set,HashSet创建一个集合set，然后用Arrays.asList(words)，把数组words转化为集合。
  为什么用Set，去重复的单词。如果例子是"time，time，bell"，去重后为"time，bell"。
  然后遍历words，用word.substring(k)和set.remove()方法移除set集合中单词的后缀。
  这里我解释一下word.substring(k)方法，例子"time，me，bell"中，set集合后为"me,time,bell"，word为me时候，k=1->word.substring(1)='e',time时候，k=1->word.substring(1)='ime',k=2->word.substring(2)='me'--在此集合中有me则用set.remove方法去除它，k=3->word.substring(3)='e',
bell和上述方法一样。
经过这个操作后，set集合中元素变为："time,bell"。
最后经过遍历，求出set的长度，记住每个元素后都要加上'#'。
### 代码

```java
class Solution {
    public int minimumLengthEncoding(String[] words) {
        Set<String> set = new HashSet(Arrays.asList(words));
        for(String word : words){
            for(int k=1;k<word.length();k++){
                set.remove(word.substring(k));
            }
        }
        int ans = 0;
        for(String word : set){
            ans += word.length() + 1;
        }
        return ans;
    }
}
```
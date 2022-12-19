### 解题思路
* HashSet构造函数传参数直接去重
* 利用Set的remove存在立刻删除，不存在无反应的功能删除自己所有的重复后缀
* 每个单词结尾用#号截止，所以每个单词长度要加1.

### 代码

```java
class Solution {
    public int minimumLengthEncoding(String[] words) {
        // Arrays.asList(words)先转为List<String>,作为Collections接口传递给HashSet构造函数
        Set<String> good = new HashSet(Arrays.asList(words));
        // 遍历每个单词
        for (String word: words) {
            // 逐个删除自己的子串，不存在无反应。
            for (int k = 1; k < word.length(); ++k) {
                good.remove(word.substring(k));
            }
        }
        // 统计字符压缩长度
        int ans = 0;
        for (String word: good) {
            ans += word.length() + 1;
        }
        return ans;
    }
}
```
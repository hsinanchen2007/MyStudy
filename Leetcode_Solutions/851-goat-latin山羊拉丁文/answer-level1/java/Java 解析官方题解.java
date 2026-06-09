### 解题思路
1. 为什么要使用 HashSet？ 因为可以很容易地将元音字母大小写加入到集合中，下面使用集合.contains() 方法也比较方便（这一点在很多类似算法题中出现了很多次）
2. 旋转辅音字母的方法：官方解答给的方法就比较好，自己之前写的是先把单词字符串转化为字符数组，然后循环移动，看到官方解答的 substring 方法，突然觉得自己很蠢，其实想想也是，这种大规模的字符移动使用 substring 是好很多
3. 我们平时也看了很多哪个 util 类有那些方法，但是就是想不到用，还是需要多刷题多总结积累经验啊。

### 代码

```java
class Solution {
    public String toGoatLatin(String S) {
        Set<Character> vowel = new HashSet();
        for (char c: new char[]{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'})
            vowel.add(c);
        int t = 1;
        StringBuilder ans = new StringBuilder();
        for (String word: S.split(" ")) {
            char first = word.charAt(0);
            if (vowel.contains(first)) {
                ans.append(word);
            } else {
                ans.append(word.substring(1));
                ans.append(word.substring(0, 1));
            }
            ans.append("ma");
            for (int i = 0; i < t; i++)
                ans.append("a");
            t++;
            ans.append(" ");
        }

        ans.deleteCharAt(ans.length() - 1);
        return ans.toString();
    }
}
```
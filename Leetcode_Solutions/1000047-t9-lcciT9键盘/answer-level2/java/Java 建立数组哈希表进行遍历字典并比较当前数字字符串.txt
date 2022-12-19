1. 建立一个**哈希数组**代表26个字母在键盘数字上的映射
2. 遍历字典中的单词，将其中的字符转化为数组中对应的数字字符一一比较当前的数字字符串，直到所有的相等加入到集合当中
```
class Solution {
    // 定义26个字母对应数字的数组映射
    char[] cToNum = new char[]{'2','2','2','3','3','3','4','4','4','5','5','5','6','6','6','7','7','7','7','8','8','8','9','9','9','9'};
    public List<String> getValidT9Words(String num, String[] words) {
        List<String> res = new ArrayList<>();
        for (String word : words) {
            int i = 0;
            for (char c : word.toCharArray()) {
                if (cToNum[c-'a'] == num.charAt(i++)) {
                    if (i == num.length()) res.add(word);
                } else break;
            }
        }
        return res;
    }
}
```

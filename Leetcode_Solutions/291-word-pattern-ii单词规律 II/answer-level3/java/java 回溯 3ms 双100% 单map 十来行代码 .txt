![1583629215(1).jpg](https://pic.leetcode-cn.com/e4938989da4380356050ccc1aba64792001e5b994643a5fff604be0a58c2642e-1583629215\(1\).jpg)

```
class Solution {
    Map<Character, String> map = new HashMap<Character, String>();
    public boolean wordPatternMatch(String pattern, String str) {
        if (pattern.length() == 0) return (str.length() == 0) ? true : false;//边界条件，如果pattern读完了字符串也正好读完就true，如果字符串没读完就false
        char letter = pattern.charAt(0);
        for (int i = 1; i <= str.length() - pattern.length() + 1; i++) {//从1位开始尝试是否有映射，由于每个pattern至少得对应一个字符，所以如果字符串剩下的字符少于pattern剩下的字符数就可以停止循环了
            String substr = str.substring(0, i), mapStr = map.get(letter);//mapStr是letter的映射，有则返回映射，没有则等于null
            if ((mapStr != null && substr.equals(mapStr)) || (mapStr == null && !map.containsValue(substr))) {//这个pattern有映射，并且等于这段字符；或者这段字符不是pattern的映射并且没有其他映射，就可以假设这个映射成立并继续尝试匹配剩下的字符
                map.put(letter, substr);//不管是否是正确答案，先放进map里面尝试
                if (wordPatternMatch(pattern.substring(1), str.substring(i))) return true;//如果正好对了就返回true
                else if (mapStr == null) map.remove(letter);//如果不对那就把这个映射取消继续下一个循环进行尝试
            }
        }
        return false;//循环跑完都没有结果当然就返回false啦
    }
}
```
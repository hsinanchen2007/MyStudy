//提供一共比较容易想的思路吧 看其他人的代码时空复杂度更好 解法都差不多 但其他人应该是走了优化吧
//其实解这道题 = 统计s中字符次数 + 无小于k的则返回s长度 有的话则在小于k的第一个字符分解（这一步可以优化 例如可以找到s中第二次出现的相同字符位置为j 分解substring(0,i) substring(j+1)）
//上代码
//统计s字符次数
```
class Solution {
    public int longestSubstring(String s, int k) {
        int[] array = new int[26];
        for(int i = 0; i < s.length(); i++){
            array[s.charAt(i)-'a']++;
        }
        for(int i = 0;i < s.length(); i++){
            if(array[s.charAt(i) - 'a'] < k){
                return Math.max(longestSubstring(s.substring(0,i),k),longestSubstring(s.substring(i+1),k));
            }
        }
        return s.length();
    }
}
```
// 加了个j 速度提高了30ms 但是感觉在笔试的时候 还是能尽快想出来比较简单的方法 会更好一些 推荐第一种解法吧
```
class Solution {
    public int longestSubstring(String s, int k) {
        int[] array = new int[26];
        for(int i = 0; i < s.length(); i++){
            array[s.charAt(i)-'a']++;
        }
        for(int i = 0;i < s.length(); i++){
            char c = s.charAt(i);
            if(array[c - 'a'] < k){
                int j = i;
                for(;j < s.length();j++){
                    if(s.charAt(j) == c){
                        break;
                    }
                }
                return Math.max(longestSubstring(s.substring(0,i),k),longestSubstring(s.substring(j+1),k));
            }
        }
        return s.length();
    }
}
```


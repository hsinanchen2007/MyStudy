### 解题思路
如果只有一个字母，那么组成的最长回文串就是自己，也就是长度为1
如果有多个字母，那么构成的最长回文串中的字符串长度是若干个偶数长度+一个奇数长度的字符串。也就是说，所有偶数长度的字符串全部要构成这个最长回文串，全部奇数长度的字符串要抽出n-1个字符构成最长回文串（也就是抽出奇数中的最大偶数个数），那么现在这个最长回文串是偶数长度的，其实他的正中间还可以插入一个字符，因此最后+1。但是如果在正中间插入字符之前，这个最长回文串的长度已经与原字符串长度相等（应该是因为原字符串中所有字符串都是偶数个的），就不能再加了。

### 代码

```java
class Solution {
    public int longestPalindrome(String s) {
        int sum=0;
        if(s==null || s.length()==0){
            return 0;
        }
        if(s.length()==1){
            return 1;
        }
        HashMap<Character, Integer> map = new HashMap<>();
        for(int i=0;i<s.length();i++){
            if(map.containsKey(s.charAt(i))){
                int num=map.get(s.charAt(i))+1;
                map.put(s.charAt(i),num);
            }else {
                map.put(s.charAt(i),1);
            }
        }
        for(Character ch:map.keySet()){
            if(map.get(ch)%2==0){
                sum+=map.get(ch);
            }else{
                sum+=map.get(ch)-1;
            }
        }
        if(sum<s.length()){
            return sum+1;
        }
        return sum;
    }
}
```
// 用hashset记录，若字符已存在则移除，不存在则插入，最后看看hashset的size就可以
class Solution {
    public boolean canPermutePalindrome(String s) {
        HashSet<Character> charSet = new HashSet();
        for(int i = 0; i < s.length(); i++){
            char c = s.charAt(i);
            if(charSet.contains(c)){
                charSet.remove(c);
            }else{
                charSet.add(c);
            }
        }
        return charSet.size() <= 1;
    }
}
class Solution {
    public String reverseLeftWords(String s, int n) {
        if(n > s.length()) return "index out of range";
        return s.substring(n,s.length()) + s.substring(0,n);
    }
}

class Solution {
    public boolean isPalindrome(String s) {
        return   new StringBuilder(s=s.replaceAll("[^A-Z0-9a-z]+","").toUpperCase()).reverse().toString().equals(s);
    }
}
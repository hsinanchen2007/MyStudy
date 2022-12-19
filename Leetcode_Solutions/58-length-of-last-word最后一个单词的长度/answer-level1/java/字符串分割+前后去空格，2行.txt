class Solution {
    public int lengthOfLastWord(String s) {
        s=s.trim();
        return s.split(" ")[s.split(" ").length-1].length();

    }
}
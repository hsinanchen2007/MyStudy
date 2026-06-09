class Solution {
    public int lengthOfLastWord(String s) {
        s=s.trim();//注意需要把末尾的空格去掉，不然会有问题，555
        int index = s.lastIndexOf(" ");
        if (index == -1) {
            return s.length();
        } else {
            return s.length() - index - 1;
        }
    }
}
若两个字符串长度相等，只需排序后后调用Arrays的equals方法即可
class Solution {
    public boolean CheckPermutation(String s1, String s2) {
        if(s1.length()==s2.length()){
            char[] char1=s1.toCharArray();
            Arrays.sort(char1);
            char[] char2=s2.toCharArray();
            Arrays.sort(char2);
            return Arrays.equals(char1,char2);
        }else{
            return false;
        }
    }
}
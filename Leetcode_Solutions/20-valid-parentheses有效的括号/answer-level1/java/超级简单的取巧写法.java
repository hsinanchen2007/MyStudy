class Solution {
    public boolean isValid(String s) {
        int length = 0;
        while (length != s.length()){
            length = s.length();
            s = s.replace("()","").replace("{}","").replace("[]","");
        }
        return s.length() == 0;
    }
}
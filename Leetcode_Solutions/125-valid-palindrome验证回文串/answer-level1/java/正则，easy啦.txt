class Solution {

    public boolean isPalindrome(String s) {
        String ss = s.toLowerCase().replaceAll("[^a-zA-Z0-9]", "");
        int i=0,j=ss.length()-1;
        while(i<j){
            if(ss.charAt(i)!=ss.charAt(j))return false;
            i++;
            j--;
        }
        return true;
    }

}
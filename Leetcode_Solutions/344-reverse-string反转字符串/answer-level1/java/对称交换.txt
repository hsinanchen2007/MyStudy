class Solution {
    public void reverseString(char[] s) {
        // char[] news = new char[s.length];
        int index = 0;
        char mid;
        for(int i=s.length-1;i>=0;i--){
            if(index!=(s.length/2)){
                mid = s[index];
                s[index] = s[i];
                s[i] = mid;
                index++;
            }
        }
    }
}
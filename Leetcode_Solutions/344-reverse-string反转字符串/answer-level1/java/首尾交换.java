class Solution {
    public void reverseString(char[] s) {
        int m=s.length-1;
        for(int i=0;i<s.length/2;i++){
            char temp=s[m--];
             m++;
             s[m--]=s[i];
             s[i]=temp;
        }
    }
}
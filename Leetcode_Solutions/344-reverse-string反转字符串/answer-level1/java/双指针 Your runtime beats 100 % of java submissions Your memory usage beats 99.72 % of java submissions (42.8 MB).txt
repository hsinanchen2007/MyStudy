public void reverseString(char[] s) {
        int i=0,j=s.length;
        char c;
        while(i<j){
            c=s[i];s[i]=s[j-1];s[j-1]=c;
            i++;j--;
        }
    }
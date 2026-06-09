    int k = 0;
        int m = s.length - 1;
        char temp;
        while(k<m){
            temp = s[k];
            s[k] = s[m];
            s[m] = temp;
            k++;
            m--;
        }
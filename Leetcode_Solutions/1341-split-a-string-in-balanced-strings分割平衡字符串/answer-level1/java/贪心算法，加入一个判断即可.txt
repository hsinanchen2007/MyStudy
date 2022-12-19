public int balancedStringSplit(String s) {
        int res = 0;
        int temp = 0;
        for(char c:s.toCharArray())
        {
            if(c=='R')temp++;
            if(c=='L')temp--;
            if(temp==0)res++;
        }
        return res;
    }
    bool validPalindrome(string s) {
        int len = s.length();
        if(2 >= len)
            return true;
        int del_idx = -1, i = 0, j = len-1;
        while((i < j) && (del_idx < len))
        {
            if(i == del_idx && i < j)
                i++;
            if(j == del_idx && i < j)
                j--;
            if(s[i] != s[j])
            {
                i = 0;
                j = len-1;
                del_idx++;
            }
            else
            {
                i++;
                j--;
            }
        }

        if(i < j)
            return false;
        return true;        
    }
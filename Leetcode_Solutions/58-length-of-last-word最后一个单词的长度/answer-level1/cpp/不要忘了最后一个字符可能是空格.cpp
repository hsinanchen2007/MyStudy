
    int lengthOfLastWord(string s) {
        int len = s.length();
        int end  = len - 1;
        int start = 0;
        while(end >= 0 && s[end] == ' ')
            end--;
        if(end < 0)
            return 0;
        start = end;
        while(start >=0 && s[start] != ' ')
            start--;
        return (end - start);
    }

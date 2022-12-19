    public:
    string reverseWords(string s) {
        int start = -1, len = s.length();
        for(int i = 0; i < len; i++)
        {
            if(-1 == start && ' ' == s[i])
                continue;
            if(-1 == start && ' ' != s[i])
            {
                start = i;
                continue;
            }
            if(-1 != start && ' ' !=  s[i] )
            {
                continue;
            }
            if(-1 != start && ' ' ==  s[i] )
            {
                reverse(s.begin()+start, s.begin()+i);
                start = -1;
            }
        }
        if(-1 != start)
            reverse(s.begin()+start, s.end());
        return s;
    }
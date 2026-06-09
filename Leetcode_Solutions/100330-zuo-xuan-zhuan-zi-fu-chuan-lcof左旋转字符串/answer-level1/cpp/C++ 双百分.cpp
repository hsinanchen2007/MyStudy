    string reverseLeftWords(string s, int n) 
    {
        string s1 = s.substr(0, n);
        string s2 = s.substr(n);
        
        reverse(s1.begin(), s1.end());
        reverse(s2.begin(), s2.end());
        
        string res = s1 + s2;
        reverse(res.begin(), res.end());
        
        return res;
    }
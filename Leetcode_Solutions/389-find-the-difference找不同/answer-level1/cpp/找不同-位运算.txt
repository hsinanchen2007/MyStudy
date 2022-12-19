    char findTheDifference(string s, string t) {
        char ans = s[0];
        for(int i = 1; i < s.size(); i++)
            ans ^= s[i];
        for(int j = 0; j < t.size(); j++)
            ans ^=t[j];
        return ans;
    }
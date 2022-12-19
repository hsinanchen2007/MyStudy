    bool IsMatch(char c)
    {
        if (c != ' ') {
            return true;
        } else {
            return false;
        }
    }

    int countSegments(string s) 
    {
        int n = s.size();
        if (n == 0) {
            return 0;
        }

        char pre = s[0];
        int ans = 0;
        for (int i = 1; i < n; i++) {
            if (IsMatch(s[i-1]) && IsMatch(s[i]) == false) {
                ans++;
            } 
        }

        if (IsMatch(s[n-1])) {
            return ans + 1;
        } else {
            return ans;
        }
    }
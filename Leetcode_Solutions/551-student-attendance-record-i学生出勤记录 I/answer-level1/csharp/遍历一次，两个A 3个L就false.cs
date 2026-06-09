public bool CheckRecord(string s) {
         int A = 0;
            for (int i = 0; i < s.Length;i++)
            {
                if (s[i] == 'A') A++;
                if (A > 1) return false;
                if(i+2<s.Length)
                {
                    if (s[i].ToString() + s[i + 1] + s[i + 2] == "LLL") return false;
                }
            }
            return true;
    }
public int MinAddToMakeValid(string S) {
         while(S.Contains("()"))  S = S.Replace("()", "");
         return S.Length;
    }
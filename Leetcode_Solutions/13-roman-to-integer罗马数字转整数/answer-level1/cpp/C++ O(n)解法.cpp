    int romanToInt(string s) {
        map<char, int> m = {{'I', 1},{'V', 5},{'X', 10},{'L', 50},{'C', 100},{'D', 500},{'M', 1000}};
        int lastNum = 0, res = 0;
        for(int i = 0 ; i < s.length() ; i ++){
            int cn = m[s[i]];
            if(cn > lastNum){
                res += cn - lastNum * 2;
            } else{
                res += cn;
            }
            lastNum = cn;
        }
        return res;
    }
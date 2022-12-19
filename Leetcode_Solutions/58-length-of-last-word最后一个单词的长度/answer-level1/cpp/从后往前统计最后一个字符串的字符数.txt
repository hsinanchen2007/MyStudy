    //先找倒数第一个非空格的索引，再继续找一个个空格索引
    int lengthOfLastWord(string s) {
        int i = s.size()-1;
        int j  =  i;
        for (;i >= 0 && j >= 0;){
            if (s[i] ==' '){
                --i;
                j = i;
                continue;
            }else{
                if (s[j] == ' '){
                    return i-j;
                }else{
                    --j;
                }
            }
        }
        return i-j;
    }
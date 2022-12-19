
    bool detectCapitalUse(string word) {
       if(word.empty())
           return false;
       int len  = word.length();
       int upperNum = 0;
       for(int i = 0; i < len; i++)
       {
           if(isupper(word[i]))
               upperNum++;
       }
       if(len == upperNum || 0 == upperNum)
           return true;
       if(1 == upperNum && isupper(word[0]))
           return true;
       return false;
        
    }
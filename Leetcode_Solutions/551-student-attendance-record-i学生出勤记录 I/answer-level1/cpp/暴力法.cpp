    public:
    bool checkRecord(string s) {
       string str1("LLL");
       int aCnt = 0;
       if(-1 != s.find(str1))
           return false;
       for(auto val : s)
       {
           if('A' == val)
              aCnt++;
           if(2 == aCnt)
               return false;
       }
       return true;  
    }
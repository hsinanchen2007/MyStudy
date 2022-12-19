
    int countSegments(string s) {
       int len = s.length();
       int i = 0, start = -1, count = 0;
       if(len == 0)
       {
           return 0;
       }
       while(i < len)
       {
           if(start != -1 && ' ' == s[i])
           {
               count++;
               start = -1;
               i++;
           }
           else
           {
               if(' ' == s[i])
               {
                   i++;
               }
               else
               {
                   start = i;
                   i++;
               }
           }
       }
       if(start != -1)
           count++;
       return count;
        
    }
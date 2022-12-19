int strStr(string haystack, string needle) {
        int hayLen=haystack.length();
        int needLen=needle.length();
        if(needLen==0)
        {
            return 0;
        }
        int i=0,j=0;
        while(i<hayLen&&j<needLen)
        {
            if(haystack[i]==needle[j])
            {
                i++;
                j++;
            }
            else
            {
                i=i-j+1;
                j=0;
            }
        }
        if(j==needLen)
        {
            return i-needLen;//found
        }
        else
        {
            return -1;//not found
        }
    }
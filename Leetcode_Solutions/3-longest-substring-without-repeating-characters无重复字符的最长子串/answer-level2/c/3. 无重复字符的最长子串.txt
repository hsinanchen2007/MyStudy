int lengthOfLongestSubstring(char * s){
    int i =0,j=0,m=0;
    bool flag = 0;
    int count = 1,max=0;
   for(i=0;*(s+i)!='\0';i++)
    {
    flag = 0;
       for(j=1;(*(s+i+j)!='\0' && flag == 0);j++){
            for(m=0;(m<j && flag == 0);m++)
                if(*(s+j+i)==*(s+i+m))
                {
                count = j;
                flag = 1;
                }
                else if(*(s+i+j+1)=='\0')
                {
                count = j+1;
                }
        }

        if(count>max)
        max = count;
        else
        count = 0;
    }
    return max;
}
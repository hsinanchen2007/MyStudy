按字符串遍历，然后特殊情况做一下特别处理；

int romanToInt(char * s){
    char n[] = {'I','V','X','L','C','D','M'};    
    int num[] = {1,5,10,50,100,500,1000};
    
    int i,j;
    int result = 0;
    int prenum = 0;
    int len = strlen(s);
    
    for (i = 0; i < len; i++)
    {
        for (j = 0; j < 7;j++)
        {
            if (s[i] == n[j])
            {
                result = result + num[j];
                if (num[j] > prenum)
                {
                    result = result - 2*prenum;
                }
                prenum = num[j];
                break;
            } 
        }
    }
    return result;
}
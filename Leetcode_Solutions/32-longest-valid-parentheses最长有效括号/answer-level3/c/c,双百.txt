int longestValidParentheses(char * s){
    int len,i;
    int max = 0;
    int *state;//state[i]记录s[i]向左匹配的最大长度
    len = strlen(s);
    if(len<2)
        return 0;
    state = (int *)malloc(sizeof(int) * len);
    memset(state,0,sizeof(int )*len);

    i = 0;
    if(s[0] == ')')
         i = 1;
    while(i<len)
    {
        if(s[i] == ')')
        {
            if(i-1 >= 0)
            {
                if(s[i-1] == '(')
                {
                    state[i] = 2;
                    if(i-2 >= 0)//
                        state[i] +=state[i-2];
                    if(state[i]>max)
                        max = state[i];
                }
                else
                {
                    if(i-1 >= 0)
                    {
                        int t = state[i-1];
                        if(i-t-1 >= 0)
                        {
                            if(s[i-t-1] == '(')
                            {
                                state[i] = state[i-1]+2;
                                if(i-t-2>=0)
                                    state[i] += state[i-t-2];//如果左端有匹配成功的，
                                                            //就会将两段进行拼接
                                if(state[i]>max)
                                    max = state[i];
                            }
                        }
                    }
                }
            }
        }
        i++;
    }
    return max;
}
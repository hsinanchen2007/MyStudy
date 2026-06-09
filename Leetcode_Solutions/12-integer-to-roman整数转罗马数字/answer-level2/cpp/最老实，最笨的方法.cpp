看到大家结题那种暴力结题只能膜拜，我用的比较笨的方法，第一次发题

![1564737323.png](https://pic.leetcode-cn.com/95967a14bbba5fdba18e84637e90381cdc0590b89b41c893d23263b0bcef1421-1564737323.png)

```
string intToRoman(int num){

    enum Roman_Type{I,V,X,L,C,D,M};
    string res = "";
    if(num > 0 && num<4000)
    {
        int temp = num;
        char rmarr[] = {'I','V','X','L','C','D','M'};
        int quotient = 0;
        for(int i=3;i>=0;i--)
        {
            quotient = temp/((int)pow(10,i));
            if(quotient != 0)
            {
                if(i == 3)
                {
                    for(int j=0;j<quotient;j++)
                    {
                        res += rmarr[M];
                    }
                }
                else if(i == 2)
                {
                    if(quotient == 9)
                    {
                        res += rmarr[C];
                        res += rmarr[M];
                    }
                    else if(quotient > 4)
                    {
                        res += rmarr[D];
                        for(int j=0;j<(quotient-5);j++)
                        {
                            res += rmarr[C];
                        }
                    }
                    else if(quotient == 4)
                    {
                         res += rmarr[C];
                         res += rmarr[D];
                    }
                    else if(quotient < 4)
                    {
                        for(int j=0;j<quotient;j++)
                        {
                            res += rmarr[C];
                        }
                    }
                }
                else if(i == 1)
                {
                    if(quotient == 9)
                    {
                        res += rmarr[X];
                        res += rmarr[C];
                    }
                    else if(quotient > 4)
                    {
                        res += rmarr[L];
                        for(int j=0;j<(quotient-5);j++)
                        {
                            res += rmarr[X];
                        }
                    }
                    else if(quotient == 4)
                    {
                         res += rmarr[X];
                         res += rmarr[L];
                    }
                    else if(quotient < 4)
                    {
                        for(int j=0;j<quotient;j++)
                        {
                            res += rmarr[X];
                        }
                    }
                }
                else if(i == 0)
                {
                    if(quotient == 9)
                    {
                        res += rmarr[I];
                        res += rmarr[X];
                    }
                    else if(quotient > 4)
                    {
                        res += rmarr[V];
                        for(int j=0;j<(quotient-5);j++)
                        {
                            res += rmarr[I];
                        }
                    }
                    else if(quotient == 4)
                    {
                         res += rmarr[I];
                         res += rmarr[V];
                    }
                    else if(quotient < 4)
                    {
                        for(int j=0;j<quotient;j++)
                        {
                            res += rmarr[I];
                        }
                    }
                }

                temp %= ((int)pow(10,i));
            }
        }
    }
    return res;
}

```

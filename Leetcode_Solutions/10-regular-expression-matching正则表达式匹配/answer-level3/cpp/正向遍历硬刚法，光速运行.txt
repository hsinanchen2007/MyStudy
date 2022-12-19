![TIM图片20200208202755.png](https://pic.leetcode-cn.com/f5c74ecfd4d0b00cf8799f431bfbbf1c965954f55a731ceb54ef6fbf6d70f0cb-TIM%E5%9B%BE%E7%89%8720200208202755.png)

简单解释：
(1). last_multi为上一个匹配的a\*字符a
(2). last_count为上一个匹配的a\*字符a的数量（打印详细匹配过程用）
(3). i,j分别指向s和p的字符，从头到尾遍历，根据匹配情况更新，遇到多情况则分支取或
(4). 主要分a/ a\*/ ./ .\*四种情况讨论，具体见注释(建议在编辑器里看)
(5). Single函数判断是否正则表达式的某字符是否为单个, Compare函数判断两字符是否可匹配(两函数仅为代码便于阅读)

    bool Single(string s,int i)
    {
        if (i<s.length() && (i+1>=s.length() || s[i+1]!='*'))
            return true;
        else
            return false;
    }

    bool Compare(char a,char b)
    {
        if (b=='.' || a==b)
            return true;
        else
            return false;
    }

    bool IsMatch(string s,string p,char last_multi,int last_count)
    {
        int slen=s.length(),plen=p.length(),i=0,j=0;
        while (i<slen && j<plen)
        {
            if (Single(p,j)) //s="a",p="?"
                if (Compare(s[i],p[j])) //s="a",p="a"
                {
                    if (p[j]=='.' && s[i]==last_multi) //s="a",p="a*|."
                    {
                        bool trial=IsMatch(s.substr(i+1,slen-i),p.substr(j,plen-j+1),last_multi,last_count++); //s="|a",p="a*|."
                        if (trial==0)
                        {
                            if (IsMatch(s.substr(i+1,slen-i),p.substr(j+1,plen-j),' ',0)) //s="|a",p="a*.|"
                                return true;
                            else
                                return false;
                        }
                        else
                            return true;
                    }
                    else
                    {
                        i++;
                        j++;
                        last_multi=' ';
                    }
                }
                else if (last_multi==s[i]) //s="a|a",p="a*|b*" 
                {
                    i++;
                    last_count++;
                }	
                else //s="a",p="b"
                {
                    return false;
                }
            else
            {
                if (p[j]=='.') //s="a",p=".*" 
                {
                    int k=j;
                    bool multi_null=0;
                    j+=2;
                    while (!Single(p,j)&&j<plen) 
                    { 
                        multi_null=1;
                        j+=2; 
                    }
                    
                    if (j==plen) //s="a",p=".*b*"
                    {
                        return true;
                    }
                    
                    k=i;
                    while (i<slen) //s="a",p=".*b*|c"
                    {
                        while (!Compare(s[i],p[j]) && i<slen)
                            i++;
                        if (i==slen) 
                            return false;
                        else //s="ac|",p=".*b*c|"
                        {
                            bool trial=IsMatch(s.substr(i+1,slen-i),p.substr(j+1,plen-j),' ',0);
                            if (trial==1)
                                return true;
                        }
                        i++;
                    }                 
                    return false;				
                } 
                
                if (!Compare(s[i],p[j])) //s="b",p="a*"
                {
                    j+=2;
                }
                else if (Single(p,j+2)) //s="a",p="a*?"
                {
                    if (!Compare(s[i],p[j+2])) //s="a",p="a*b" 
                    {
                        while (i<slen && Compare(s[i],p[j]))
                        {
                            i++;
                        }
                        j+=2;
                        last_multi=' ';
                    }
                    else if (p[j+2]!='.') //s="a",p="a*a"
                    {
                        last_multi=s[i];
                        last_count=0;
                
                        j+=3;
                        i++;
                    }
                    else //s="a",p="a*."
                    {
                        int k=i;
                        while (s[i]==p[j] && i<slen)
                            i++;
                        if (i==slen) //s="aaa",p="a*."
                            if (j+2==plen-1) 
                                return true; 
                            else   
                                return false;
                        bool trial=IsMatch(s.substr(i-1,slen-i+1),p.substr(j+2,plen-j-1),' ',0); //s="a|ab",p="a*|."
                        if (trial==0)
                        {
                            if (IsMatch(s.substr(i,slen-i),p.substr(j+2,plen-j-1),' ',0)) //s="aa|b",p="a*|."
                                return true;
                            else
                                return false;
                        }
                        else
                            return true;	
                    }
                }
                else //s="a",p="a*b*"
                {
                    return (IsMatch(s.substr(i+1,slen-i),p.substr(j+2,plen-j-1),s[i],1)) || (IsMatch(s.substr(i,slen-i+1),p.substr(j+2,plen-j-1),s[i],0));
                }
            }			
        }
        
        if (i<slen)
        {
            while (i<slen && last_multi==s[i]) 
            {
                last_count++;
                i++;
            }
            if (i==slen) //s="a",p="a*|"
            {
                return true;
            } 
            else
            {
                return false;
            }
        }
        if (j<plen)
        {
            while (j<plen && !Single(p,j))
            {
                j+=2;
            }
            if (j==plen) //s="",p="|a*"
                return true;
            else
            {
                return false;
            }
        }
        return true;
    }

    bool isMatch(string s,string p)
    {
        return IsMatch(s,p,' ',0);
    }

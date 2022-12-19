### 解题思路
此处撰写解题思路

### 代码

```c

int findsame(char *s, int k,int j)
{
	while(*(s+k)!=*(s+j)&&k<j)
	{
		k++;
	}
	if(j==k)
	{
		return 0;//不存在相等的
	}
	else
		return 1;//存在相等的
}
int lengthOfLongestSubstring(char * s)
{
    if(*s=='\0')
    {
        return 0;
    }
    else
    {
        int N=strlen(s);
        int a[N];
        int i,j;
        int k=0;
        for(i=0;i<N;i++)
        {
            a[i]=1;
        }
        for(i=0;i<N-1;i++)
        {
            for(j=i+1;j<N;j++)
            {
                if(*(s+i)!=*(s+j))
                    {    
                        k=i;    		
                        if(!findsame(s,k,j))
                        {
                            a[i]=a[i]+1;
                        }
                        else
                            break;
                    }
                else
                {
                break;  
                }       		
            } 
                
        }
        int t=a[0];
        for(i=0;i<N-1;i++)
        {
            if(a[i]>t)
            {
                t=a[i];
            }
        }
        return t;
    }
}
```
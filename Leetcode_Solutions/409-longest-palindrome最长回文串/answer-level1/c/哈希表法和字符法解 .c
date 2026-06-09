两种方法代码都比较多


```c

int longestPalindrome(char * s){
    int l = 0;
    int sum = 0;
    int total = 0;
    int flag = 0;
    int flag2 = 0;
    l = strlen(s);
    if(l ==1)
    {
        return 1;
    }


    for (int i = 0;i<l;i++)
    {
        flag = 0;
        flag2 = 0;
        sum = 0;
    
        if(i >= 1)
        {
            for(int k = 0;k<i;k++)
            {
                if(s[k] == s[i])
                {
                    flag = 1;
                    break;
                }
            }
        }
        if(flag ==1)
        {
            continue;
        }
        for(int j =i+ 1;j <l;j++)
        {

            if(s[i] == s[j])
            {
                sum++;
                flag2 = 1;
                
            }
        }
        if(flag2 ==1)
        {
            if((sum + 1) % 2 == 0)
            {
                total =  total + sum +1;
            }   
            else
            {
                total = sum+ total ;
            }
                     
        }

    }
    if(l > 2)
    {
     if(total %2 ==0)
      {
         total = total +1;
     }
    }
  if(total > l)
  {
      total = l;
  }
  if(total == 0)
  {
      total = 1;
  }
    return total;
}

//哈希表解法
int longestPalindrome(char * s)
{
    int l = 0;
    int total = 0;
    l = strlen(s);
    int hash[128] ;
    memset(hash,0,sizeof(hash));
    if(l ==1 )
    {
        return l;
    }
    for (int i = 0;i < l ;i++ )
    {
        for(int j = 0;j< 128;j++)
        {
            if(s[i] ==j )
            {
                hash[j]++;
                continue;
            }
        }
        
    }
    for(int i = 0;i<128;i++)
    {
        if(hash[i] % 2 == 0)
        {
            total = hash[i] + total;
        }
        else
        {
            total = hash[i] + total -1;
        }
        
    }
    if(total %2 == 0)
    {
        total = total+1;
    }
    if(total > l)
    {
        total = l;
    }
    return total;
# }
```
### 解题思路
此处撰写解题思路
C遍历查看每个出现的次数，偶数加次数，奇数加次数-1.有奇数出现最后再加1；全偶数不能变。
### 代码

```c
int longestPalindrome(char * s){
                int data[52]={0};
                if(strlen(s)==0)
                {
                    return 0;
                }
                else{
                    for(int i=0;i<strlen(s);i++)
                    {
                        if(s[i]-'a'>=0&&s[i]-'z'<=0)
                        {
                            data[s[i]-'a']+=1;
                        }
                        else if(s[i]-'A'>=0&&s[i]-'Z'<=0){
                            data[s[i]-'A'+26]+=1;
                        }
                    }
                }
                int key=0;
                for(int i=0;i<52;i++)
                {
                    printf("%d",data[i]);
                    if(data[i]%2==0)
                    {
                        key+=data[i];
                    }
                    else{
                        key+=data[i]-1;
                    }
                }
                if(key<strlen(s))
                {
                    key+=1;
                }
                return key;
}
```
### 解题思路
此处撰写解题思路
![TIM截图20200308130830.jpg](https://pic.leetcode-cn.com/23aaf3a36bc17727ab6b2e6fba6837d1e0d49543026858326add190cf222258a-TIM%E6%88%AA%E5%9B%BE20200308130830.jpg)

### 代码

```c
bool CheckPermutation(char* s1, char* s2){
    int len1=0,len2=0;
    int i,j;
    len1=strlen(s1);
    len2=strlen(s2);
    if(len1!=len2)
        return false;
    for(i=0;i<len1;i++)
    {
        for(j=0;j<len1-i-1;j++)
        {
            if(s1[j]>s1[j+1])
            {
                char temp;
                temp=s1[j];
                s1[j]=s1[j+1];
                s1[j+1]=temp;
            }
        }
        
    }

    for(i=0;i<len2;i++)
    {
        for(j=0;j<len2-i-1;j++)
        {
            if(s2[j]>s2[j+1])
            {
                char temp;
                temp=s2[j];
                s2[j]=s2[j+1];
                s2[j+1]=temp;
            }
        }
    }
    for(i=0;i<len1;i++)
    {
        if(s1[i]!=s2[i])
            return false;
    }

    return true;
}
```
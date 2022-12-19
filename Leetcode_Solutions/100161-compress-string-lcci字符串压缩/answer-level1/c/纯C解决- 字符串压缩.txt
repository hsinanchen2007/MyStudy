### 解题思路
难点就是每个字符的个数>9，需要翻转

### 代码

```c
#define MaxSize 100000
char* compressString(char* S){
    int length=strlen(S);
    int i=1;

    //for result 
    char *result=(char *)malloc(sizeof(char)*(MaxSize+1));
    int index=0;
    int count=1;
    char temp=S[0];

    for(i=1;i<length;i++)
    {
        if(S[i]==temp)
        count++;
        else
        {
            result[index++]=temp;
            if(count<10)
            result[index++]=count+'0';
            else
            {
                int start=index;
                while(count)
                {
                    result[index++]=count%10+'0';
                    count/=10;
                }
                int end=index-1;
                while(start<end)//翻转数字
                {
                    char temp=result[start];
                    result[start]=result[end];
                    result[end]=temp;
                    end--;
                    start++;
                }
            }
            temp=S[i];
            count=1;
        }
    }
    if(i==length)
    {
            result[index++]=temp;
            if(count<10)
            result[index++]=count+'0';
            else
            {
                int start=index;
                while(count)
                {
                    result[index++]=count%10+'0';
                    count/=10;
                }
                int end=index-1;
                while(start<end)
                {
                    char temp=result[start];
                    result[start]=result[end];
                    result[end]=temp;
                    end--;
                    start++;
                }
            }
    }
    result[index]='\0';
    if(index>=length)
    return S;
    return result;
}
```
### 解题思路
小白的暴力解法
![image.png](https://pic.leetcode-cn.com/457fa8bf96d9028fbd242c4d5a2d4fbfa37071de1365b3b4c068e5d1fab6257a-image.png)

### 代码

```c
char* compressString(char* S){
    char *a=(char *)malloc(sizeof(char)*51000);
    a[0]=S[0];
    int len1=0,len=strlen(S),num=1,num1=0,num2=0;
    for(int i=1;i<len&&len1<=50000;i++)
    {
        
        if(S[i]==a[len1])
        {
            num++;
        }else
        {
            num1=num+1;
            while (num1!=0)
            {
                num1=num1/10;
                num2++;
            }
            int k=num2;
            while(k!=0)
            {
                num1=num;
                int j=k-1;
                while(j!=0)
                {
                    num1=num1/10;
                    j--;
                }
                if(k!=num2)
                {
                    num1=num1%10;
                }
                k--;
                a[++len1]='0'+num1;
            }
            num2=0;
            num=1;
            a[++len1]=S[i];
        }
    }
   
     num1=num+1;
            while (num1!=0)
            {
                num1=num1/10;
                num2++;
            }
            int k=num2;
            while(k!=0)
            {
                num1=num;
                int j=k-1;
                while(j!=0)
                {
                    num1=num1/10;
                    j--;
                }
                if(k!=num2)
                {
                    num1=num1%10;
                }
                k--;
                a[++len1]='0'+num1;
            }

    a[++len1]='\0';
    if(len1<len)
    return a;
    else
    return S;
}
```
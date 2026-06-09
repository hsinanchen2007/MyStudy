### 解题思路
此处撰写解题思路

### 代码

```c
void reverse(char *a);
char * addBinary(char * a, char * b){
    // reverse(a);
    // reverse(b);

    int lena=strlen(a);
    int lenb=strlen(b); 
    int lenmax=lena>lenb?lena:lenb;
    char *res=(char*)malloc(sizeof(char)*(lenmax+2));
    res[lenmax+1]='\0';
    int k=0;
    for(int i=0;i<lenmax+1;i++)
        res[i]='0';
    
    for(int i=lenmax;i>=0;i--)
    {
        if(lena>0&&lenb>0)
        {
            if((a[lena-1]=='1'&&b[lenb-1]=='0')||(a[lena-1]=='0'&&b[lenb-1]=='1'))
            {
                if(res[i]=='0')
                    res[i]='1';
                else
                {
                    res[i]='0';
                    res[i-1]='1';
                }
            }
            if((a[lena-1]=='1'&&b[lenb-1]=='1'))
            {
                res[i-1]='1';
            }
            
        }
        else if(lena>0)
        {
            if(a[lena-1]=='1')
            {
                if(res[i]=='0')
                    res[i]='1';
                else
                {
                    res[i]='0';
                    res[i-1]='1';
                }
            }
        }
        else if(lenb>0)
        {
            if(b[lenb-1]=='1')
            {
                if(res[i]=='0')
                    res[i]='1';
                else
                {
                    res[i]='0';
                    res[i-1]='1';
                }
            }
        }



        lena--;
        lenb--;
    }

    if(res[0]=='0')
    {
        for(int i=0;i<lenmax;i++)
        {
            res[i]=res[i+1];
        }
        res[lenmax]='\0';
    }








    return res;
}


void reverse(char *a)
{
    int len=strlen(a);
    for(int i=0;i<len/2;i++)
    {
        char temp=a[len-i-1];
        a[len-i-1]=a[i];
        a[i]=temp;
    }

}
```
### 解题思路
简单粗暴 暴力if

### 代码

```c


char * intToRoman(int num){
    char *a=(char*)calloc(100,sizeof(char));
    int len=0;
    int n;
    if(num>=1000)
    {
        n=num/1000;
        for(int i=0;i<n;i++)
        {
            a[len++]='M';
        }
    }
    if(num%1000>=900)
    {
        a[len++]='C';
        a[len++]='M';
    }else if(num%1000>=500)
    {
        a[len++]='D';
        n=(num%1000-500)/100;
        for(int i=0;i<n;i++)
        {
            a[len++]='C';
        }
    }else if(num%1000>=400)
    {
        a[len++]='C';
        a[len++]='D';
    }else if(num%1000>0)
    {
        n=(num%1000)/100;
        for(int i=0;i<n;i++)
        {
            a[len++]='C';
        }
    }

     if(num%100>=90)
    {
        a[len++]='X';
        a[len++]='C';
    }else if(num%100>=50)
    {
        a[len++]='L';
        n=(num%100-50)/10;
        for(int i=0;i<n;i++)
        {
            a[len++]='X';
        }
    }else if(num%100>=40)
    {
        a[len++]='X';
        a[len++]='L';
    }else if(num%100>0)
    {
        n=(num%100)/10;
        for(int i=0;i<n;i++)
        {
            a[len++]='X';
        }
    }

     if(num%10>=9)
    {
        a[len++]='I';
        a[len++]='X';
    }else if(num%10>=5)
    {
        a[len++]='V';
        n=(num%10-5);
        for(int i=0;i<n;i++)
        {
            a[len++]='I';
        }
    }else if(num%10>=4)
    {
        a[len++]='I';
        a[len++]='V';
    }else if(num%10>0)
    {
        n=(num%10);
        for(int i=0;i<n;i++)
        {
            a[len++]='I';
        }
    }

    return a;
}
```
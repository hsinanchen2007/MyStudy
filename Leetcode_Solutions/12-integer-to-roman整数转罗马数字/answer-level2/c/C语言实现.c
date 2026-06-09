### 解题思路
先把整形拆开分别存入数组a中，然后利用双重循环来不断找出每一个数对应的罗马数值，记得末尾补 \0

### 代码

```c
char * intToRoman(int num)
{
    int tmp = 0, ret = num, fre = 0,t = 0;
    int a[11] = {0};   //int 最大值为11位，所以设置了11个空间
    while(ret > 9)
    {
        a[t++] = ret % 10;   //将每位数分别存入a 中
        ret /= 10;
        ++fre;
    }
    a[t] = ret; 
    fre += 1;    //得到num 的位数
    char* s = (char*)malloc(sizeof(char) * 300);  //多出的空间用来存 \0
    int x = 0;
    for(int i = fre - 1; i >= 0; --i)
    {
        int tmp = a[i] * (pow(10,i));
        while(tmp)
        {
            if(tmp < 4)
            {
                s[x++] = 'I';
                tmp -= 1;               
            }
            else if(tmp == 4)
            {
                s[x++] = 'I';
                s[x++] = 'V';
                tmp -= 4;
            }
            else if(tmp > 4 && tmp < 9)
            {
                s[x++] = 'V';
                tmp -= 5;
            }
            else if(tmp == 9)
            {
                s[x++] = 'I';
                s[x++] = 'X';
                tmp -= 9;
            }
            else if(tmp > 9 && tmp < 40)
            {
                s[x++] = 'X';
                tmp -= 10;
            }
            else if(tmp == 40)
            {
                s[x++] = 'X';
                s[x++] = 'L';
                tmp -= 40;
            }
            else if(tmp > 49 && tmp < 90)
            {
                s[x++] = 'L';
                tmp -= 50;
            }
            else if(tmp == 90)
            {
                s[x++] = 'X';
                s[x++] = 'C';
                tmp -= 90;
            }
            else if(tmp > 99 && tmp < 400)
            {
                s[x++] = 'C';
                tmp -= 100;
            }
            else if(tmp == 400)
            {
                s[x++] = 'C';
                s[x++] = 'D';
                tmp -= 400;
            }
            else if(tmp > 499 && tmp < 900)
            {
                s[x++] = 'D';
                tmp -= 500;
            }
            else if(tmp == 900)
            {
                s[x++] = 'C';
                s[x++] = 'M';
                tmp -= 900;
            }
            else if(tmp > 999)
            {
                s[x++] = 'M';
                tmp -= 1000;
            }
        }
    }
    s[x] = '\0';
    return s;
    
}
```
### 解题思路
此处撰写解题思路

### 代码

```c
char* intToRoman(int num)
{
    char* p, * head;
    head = (char*)malloc(sizeof(char) * 100);
    p = head;
    while (num)//将num从高向下减
    {
        if (num >= 1000)
        {
            *p++ = 'M';
            num -= 1000;
        }
        else if (num >= 900)
        {
            *p++ = 'C';
            *p++ = 'M';
            num -= 900;
        }
        else if(num >= 500)
        {
            *p++='D';
            num-=500;
        }
        else if (num >= 400)
        {
            *p++ = 'C';
            *p++ = 'D';
            num -= 400;
        }
        else if (num >= 100)
        {
            *p++ = 'C';
            num -= 100;
        }
        else if (num >= 90)
        {
            *p++ = 'X';
            *p++ = 'C';
            num -= 90;
        }
        else if (num >= 50)
        {
            *p++ = 'L';
            num -= 50;
        }
        else if (num >= 40)
        {
            *p++ = 'X';
            *p++ = 'L';
            num -= 40;
        }
        else if (num >= 10)
        {
            *p++ = 'X';
            num -= 10;
        }
        else if (num >= 9)
        {
            *p++ = 'I';
            *p++ = 'X';
            num -= 9;
        }
        else if (num >= 5)
        {
            *p++ = 'V';
            num -= 5;
        }
        else if (num >= 4)
        {
            *p++ = 'I';
            *p++ = 'V';
            num -= 4;
        }
        else if (num >= 3)
        {
            *p++ = 'I';
            *p++ = 'I';
            *p++ = 'I';
            num -= 3;
        }
        else if (num >= 2)
        {
            *p++ = 'I';
            *p++ = 'I';
            num -= 2;
        }
        else if (num >= 1)
        {
            *p++ = 'I';
            num -= 1;
        }
    }
    *p = '\0';
    return head;
}

// I             1
// II            2
// III           3
// IV            4
// V             5
// IX            9
// X             10
// XL            40
// L             50
// XC            90
// C             100
// CD            400
// D             500
// CM            900
// M             1000
```
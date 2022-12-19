### 解题思路
![image.png](https://pic.leetcode-cn.com/d4461e9e8702041d2228652e41feb40adaf8a9dd15c42fc7a27926f1cf8edc1b-image.png)

不是很熟悉C语言，看到其他人的都好现象没这么长，有时间看看其他人的解法应该是很好的。
就是如题目所述的思路，a是S的一个副本，b用来保存重复信息，int类型的length和b_length分别是他们的长度，a_length是重复的字符的长度
遍历S之后得到a的长度，再次一个个寻找a中的重复并将信息存储到b中
代码长是因为不知道比如Z出现了830次该怎么表示，采用了很笨的方法把他表示为8，3，0，然后用字符的形式表示出来，所以那一段很重复并且很难看。

### 代码

```c
#include<math.h>
char* compressString(char* S){
    int length = 0;
    int a_length = 0;
    int b_length = 0;
    char* a = S;
    int* c = NULL;
    while(*a) 
    {
        length++;
        a++;
    }
    char* b = (char*)malloc(500000*(sizeof(char))); //500000是因为有一个50000没通过，应该是b最后的长度超过了，emm，那应该给2*50000就行，这个有点大了。
    //printf("%d\n",length);
    a = S;
    while(*a)
    {
        if(a == S || *a == *(a-1) )     //用来对多个重复的字符计数
        {
            if(*a == *(a+1) && a != S + length) a_length ++;
            else
            {
                a_length++;
                *b = *a;
                b++;
                if(a_length >= 1000)   //以下的所有if-else都是a_length的字符表示
                {
                    int c = a_length / 1000;
                    int d = a_length % 1000 / 100;
                    int e = a_length % 1000 % 100 / 10;
                    int f = a_length % 10;
                    *b = '0' + c;
                    b++;
                    *b = '0' + d;
                    b++;
                    *b = '0' + e;
                    b++;
                    *b = '0' + f;
                    b++;
                    b_length += 5;
                }
                else if(a_length >= 100)
                {
                    int c = a_length / 100;
                    int d = a_length % 100 /10;
                    int e = a_length % 10;
                    *b = '0' + c;
                    b++;
                    *b = '0' + d;
                    b++;
                    *b = '0' + e;
                    b++;
                    b_length += 4;
                }
                else if(a_length >= 10)
                {
                    int c = a_length / 10;
                    int d = a_length % 10;
                    *b = '0' + c;
                    b++;
                    *b = '0' + d;
                    b++;
                    b_length += 3;
                }
                else
                {
                    *b = '0' + a_length;
                    b++;
                    b_length += 2;
                }
            }
        }
        else if(*a != *(a-1) && *a != *(a+1))   //这是对只出现了一次的字符的计数
        {
            a_length = 1;
            *b = *a;
            b++;
            *b = '0' + a_length;
            b++;
            b_length += 2;
        }
        else a_length = 1;      //这是对多次出现字符的第一次计数
        //printf("第%d个出现了%d次\n",a-S,a_length);
        a++;
    }
    *b = '\0';
    if(b_length >= length)return S;     //判断b还是原字符长
    else return b - b_length;
}
```
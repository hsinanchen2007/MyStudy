### 解题思路
考虑到本题最后的条件，就是在字符串当中，每个单词由单个空格分隔，并且字符串中不会有任何额外的空格，这个条件使得这道题的难度降低不少。

主要的思路是遍历字符串数组，遇到空格就将空格前面的[单词进行反转](http://datacruiser.io/2019/09/08/Leetcode-Tencent-50-344-Reverse-String/)，一遍遍历以后只剩下最后一个单词未反转。出了循环以后单独再遍历一下最后一个单词，然后直接返回原数组。具体代码如下：

### 代码

```c

void reverseString(char* s, int sSize)
{
    int head = 0, tail = sSize - 1;
    char tmp;
    
    while(head < tail)
    {
        tmp = s[head];
        s[head] = s[tail];
        s[tail] = tmp;
        head++;
        tail--;
    } 
}



char * reverseWords(char * s)
{
    int length = strlen(s);
    int index = 0;
    
    for(int i = 0; i < length; i++)
    {
        if(s[i] == ' ')
        {
            reverseString(s + index, i - index);
            index = i + 1;
            //break;
        }
    }
    reverseString(s + index,  length - index);
   
    return s;
}


```
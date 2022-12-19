考虑到本题最后的条件，就是在字符串当中，每个单词由单个空格分隔，并且字符串中不会有任何额外的空格，这个条件使得这道题的难度降低不少。

主要的思路是遍历字符串数组，遇到空格就将空格前面的单词进行反转，一遍遍历以后只剩下最后一个单词未反转。出了循环以后单独再遍历一下最后一个单词，然后直接返回原数组。具体代码如下：


```c []
/* 单个单词的反转，注意输入的参数
s: 字符串数组的头指针
sSize: 字符串数组的长度
*/
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
    int length = strlen(s);                    //获取字符串的长度
    int index = 0;                             //记录空格所在位置后一个元素的下标，用于表示输入字符串当中单个单词所在位置
    
    for(int i = 0; i < length; i++)
    {
        if(s[i] == ' ')
        {
            reverseString(s + index, i - index);
            index = i + 1;                     //更新下一个单词起始下标
            //break;
        }
    }
    reverseString(s + index,  length - index); //退出循环后对最后一个单词进行反转
   
    return s;
}
```

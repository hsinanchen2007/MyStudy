### 解题思路
两个指针head，rear分别指向子串的首尾，另设一个指针pointer用来将子串中的每位与新增位即rear进行比较
当输入字符串长度不为0时，输出值至少为1，返回值初值即设为1
基本思路：
当子串中每一位与新增位都不相同时（当pointer=rear时，即为子串中每位都与新增位比较完毕）
即长度加1，再新增一位
否则，子串滑动
最简单的滑动即为首部向前移一位，尾部为首部次位。


### 代码

```c
int lengthOfLongestSubstring(char * s){
    int length = strlen(s);

    //如果字符串为空，或者只有一个字符，则返回0和1
    if(length==0 || length==1)return length;
    
    //maxlen为最长子串长度
    int maxlen=1;

    int head = 0;
    int rear = 1;
    int pointer = 0;
    int len=1;

    while(rear < length)
    {
        while(pointer != rear)
        {
            if(s[pointer] != s[rear]) pointer++;
            else
            {
                head++;
                pointer = head;
                rear = head+1;
                len=1;
                //当head=length-1，pointer=head，rear=length时
                //虽然已经不满足rear<length，但是仍然要先完成内层while才能跳出外层while
                if(rear==length)return maxlen;
            }
        }
         len++;
         if(maxlen<len)maxlen=len;
         rear++;
         pointer = head;
    }
    return maxlen;
}
```
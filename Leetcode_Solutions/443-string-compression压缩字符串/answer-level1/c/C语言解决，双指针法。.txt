### 解题思路
用指针anchor指向连续块的起始位置，用指针read指向不同于该连续块字符的第一个位置，用write指针更新字符数组。
read-anchor即为连续块长度，若为1，则不写入，一趟完成后让anchor指向read，即继续扫描下一连续块。

### 代码

```c
int compress(char* chars, int charsSize){
    int write = 0;
    char buf[1000];
    for(int read=0, anchor=0;read<charsSize;anchor=read)
    {
        while(read<charsSize&&chars[read]==chars[anchor])
            read++;
        chars[write++] = chars[anchor];
        if(read-anchor==1)
            continue;
        sprintf(buf,"%d",read-anchor);
        for(int i=0;i<strlen(buf);i++)
            chars[write++] = buf[i];
    }
    return write;
}
```
### 解题思路
C语言冷知识：数组下标可以是负号，表示当前数组指针往前找，和python略有差异；数组名和数组下标还可以反着写，a[i] = i[a];负号时注意优先级，(-i)[s],强化数组下标的语义。

### 代码

```c
int lengthOfLastWord(char * s){
    int length = 0;
    int cur = 0;
    bool IsBreak = false;
    
    for (cur = strlen(s) - 1; 0 <= cur; cur--)
    {
        if (cur[s] == ' ' && IsBreak == true)
        {
            break;
        }

        if (cur[s] != ' ')
        {
            length++;
            IsBreak = true;
        }
    }

    return length;
}
```
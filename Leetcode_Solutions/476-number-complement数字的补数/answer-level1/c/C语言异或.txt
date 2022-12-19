### 解题思路
此处撰写解题思路

### 代码

```c
int findComplement(int num)
{
    int mask = 0, i = 0;
    while (mask < num)
        mask += pow(2, i++);
    return mask ^ num;
}
```
### 解题思路
此处撰写解题思路

### 代码

```c
int maximum69Number (int num)
{
    int temp = num;
    int index = -1, i = 0;
    while (temp > 0)
    {
        if (temp % 10 == 6)
            index = i;
        temp /= 10;
        i++;
    }
    return index == -1 ? num : num + 3 * pow(10, index); 
}
```
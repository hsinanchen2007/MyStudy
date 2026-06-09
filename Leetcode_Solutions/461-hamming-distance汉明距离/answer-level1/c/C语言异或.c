### 解题思路
此处撰写解题思路

### 代码

```c
int hammingDistance(int x, int y)
{
    int dis = 0;
    int xor = x ^ y;
    while (xor)
    {
        if (xor % 2 != 0)
            dis++;
        xor /= 2;
    }
    return dis;
}
```
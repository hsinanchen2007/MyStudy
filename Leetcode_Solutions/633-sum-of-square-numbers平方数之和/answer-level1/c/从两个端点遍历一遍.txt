### 解题思路
此处撰写解题思路

### 代码

```c

bool judgeSquareSum(int c){
    int i = 0;
    int j = sqrt(c);
    bool res = false;
    while (i<=j)
    {
        if (pow(i,2)+pow(j,2) == c)
        {
            res = true;
            break;
        }
        else if (pow(i,2)+pow(j,2) < c)
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    return res;
}
```
**方法思路：**
1、int类型最大数2,147,483,647有10位，用A[10]记录下，再循环比对

代码如下：

bool isPalindrome(int x){
    if (x < 0)
        return false;
    else if (x >= 0 && x < 10)
        return true;
    
    int num[10], i, j, k = 0;
    memset(num, 0, sizeof(num));

    while (x != 0)
    {
        num[k++] = x % 10;
        x /= 10;
    }

    for (i = 0, j = k-1; i < j; ++i, --j)
        if (num[i] != num[j])
            return false;

    return true;
}


2、x = 1221 ==>> x = 122,  y = 1
            ==>> x = 12,   y = 12  (相等，是回文)
代码如下：

bool isPalindrome(int x){
    if (x >= 0 && x < 10)
        return true;
    else if (x < 0 || x % 10 == 0)
        return false;
    
    int y = 0;
    while (y < x)
    {
        y = y * 10 + x % 10;
        if (x == y)
            return true;
        x /= 10; 
    }

    if (x == y)
        return true;
    else
        return false;
}

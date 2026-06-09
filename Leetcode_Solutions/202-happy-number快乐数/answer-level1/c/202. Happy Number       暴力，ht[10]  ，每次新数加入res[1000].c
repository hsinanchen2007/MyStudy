### 解题思路
也可以把新数放到hash表里， 或者用快慢指针（快指针每循环算两次）



编写一个算法来判断一个数是不是“快乐数”。

一个“快乐数”定义为：对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和，然后重复这个过程直到这个数变为 1，也可能是无限循环但始终变不到 1。如果可以变为 1，那么这个数就是快乐数。

示例: 

输入: 19
输出: true
解释: 
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1



### 代码

```c
bool isHappy(int n){
    int i = 0, j = 0, temp, sum, last;
    int ht[10] = {0};
    int res[1000] = {0};

    for (i = 0; i < 10; i++)
        ht[i] = i*i;
    
    temp = n;
    while (temp != 1) {
        for (i = 0; i < j; i++){
            if (res[i] == temp)
                return false;
        }
        if (i == j)
            res[j++] = temp;
        
        sum = 0;
        while (temp) {
            last = temp%10;
            sum += ht[last];
            temp = temp/10;
        }

        temp = sum;
    }
    return true;
}
```
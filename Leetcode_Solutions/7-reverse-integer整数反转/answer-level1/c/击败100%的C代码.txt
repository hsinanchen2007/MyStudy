### 解题思路
这个题关键点是溢出处理和取位数算法，溢出处理花费了N长时间，另外第一次用了两次循环，4ms，优化为一次循环
///////////////////////////////////////////////////
1、执行用时 :0 ms, 在所有 C 提交中击败了100%的用户；
2、内存消耗 :7.1 MB, 在所有 C 提交中击败了74.70%的用户；

### 代码

```c
/*
strcut ListNode{
    int val;
    strcut ListNode* next;
};
*/
//#include <math.h>
int reverse(int x){
    int i = 0, j = 1, k = 1;
    long y = 0;
    int min, max;
    int len;

    /* 合法性判断 */
    min = 0 - pow(2, 31);
    max = pow(2, 31) - 1;
    if ((x <= min) || (x >= max))
    {
        return 0;
    }

    /* 特殊值处理，零 */
    if (0 == x)
    {
        return 0;
    }

    if (x > 0)
    {
        k = 1;
        while(k > 0){
            k = x/((int)pow(10, i++));
        }
    }
    else{
        k = -1;
        while(k < 0){
            k = x/((int)pow(10, i++));
        }
    }
    
    len = i;
    /* 生产顺序链 */
    for (i = len - 2, k = 0; i >= 0; i--)
    {
        j = (x/((int)pow(10, i)))%10;
        y += j * pow(10, k++);
    }

    if ((int)y != y)
    {
        y = 0;
    }

    return y;
}
```
### 解题思路
也比较简单，只要抓住规律就好办了。
分析题：一个一维数组代表一个整数（高位在前）来进行加一
       整数加一的话肯定要从低位加，所以我就判断数组的最后一位是不是10（因为题中说明元素为个数），如果是10的话我就置0并把前一位加一，然后循环判断，直到不为10。
       有几个需要注意的地方：1.进位 如果输入[9,9],加一就变成了100，所以我附加了一个判断语句，判断数组0位是不是0，如果是就申请内存的时候多申请一个。2.先前说的 “如果是10就置0并把前一位加一” 这是有风险的，如果输入[9]那就越界了，所以我双重判断 数据为10并且输入的位数不为1，这就解决了。
       这种方法比别的for循环嵌套速度快多了，我原先也是想用嵌套的，结果一直出错误，改的我心烦，一气之下就全删了^~^,然后就想用别的方法，哎~突然灵光一现就出来了这个思路。
       总之，不要怕难，我也是刚学数据结构和算法，也知道这些题对我们这些菜鸟来说难，算法题库我现在才做出来四道题呢，但是难我们也做出来了，这才能成长，在此给你们点鼓励，愿我们一起共勉，加油！！！
### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){
    int num;
    num = digitsSize;
    digits[digitsSize - 1]++;
    for(int i = digitsSize - 1; i >= 0; i--)  //判断加一之后数的位数
    {                                          
        if(digits[0] == 10)   
        {
           num = digitsSize + 1;
            break;
        }
        else if(digits[i] == 10 && i != 0) //防止输入9 数组越界
        {
            digits[i] = 0;
            digits[i - 1]++;
        }
        
        else break;
    }
    *returnSize = num;
    int *new = (int *)malloc(sizeof(int) * num);
    if(num > digitsSize)
    {
        new[0] = 1;
        for(int i = 1; i <= digitsSize; i++)
        {
            new[i] = 0;
        }
    }
    else if(num == digitsSize)
    {
        for(int i = 0; i < digitsSize; i++)
        {
            new[i] = digits[i];
        }
    }
    return new;

}
```
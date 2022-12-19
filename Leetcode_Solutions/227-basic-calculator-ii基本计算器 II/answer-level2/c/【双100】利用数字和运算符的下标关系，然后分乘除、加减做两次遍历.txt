### 解题思路
注释已经说明了一切

// 0 1 2 3 4 5 6 7 8 9 10 11 12   k
// | | | | | | | | | |  |  |  |
// 1 + 2 * 3 / 4 + 5 *  6  -  7   i
// | | | | | | | | | |  |  |  |
// | 0 | 1 | 2 | 3 | 4  |  5  |
// |   |   |   |   |    |     |
// 0   1   2   3   4    5     6   j
// k = 2*i+1
// i附近的两个数字：k-1,k+1，即(2*i) (2*i+2), j=k/2,  i, i+1
// 即运算符数组中第i个运算符，其两边的数字，对应数字数组的序号是i，i+1
// 总是将运算好的数据放在右边的数字（i+1）里，并将数字i修改成INT_MIN，
// 做完乘除后，做加减的时候需要找一下右边数字，因为可能不是i+1了，所以比乘除多了个while循环

### 代码

```c
// 数字的个数 = 运算符个数 + 1
int getOprNumber(char* s)
{
    int num = 0;
    while('\0' != *s)
    {
        if(*s=='+' || *s=='-' || *s=='*' || *s=='/')
        {
            num ++;
        }    
        s++;
    }

    return num;
}



int calculate(char * s){
    long long sum = 0;
    long long mul = 1;
    int num_opr = 0, num_digital = 0;
    int i = 0, j = 0, k = 0;
    long long digital = 0;
    char* p = s;
    
    num_opr = getOprNumber(s);
    num_digital = num_opr+1;

    long long* list_digital = (long long*)malloc(num_digital*sizeof(long long));
    char* list_opr =  (char*)malloc((num_opr+1)*sizeof(char));

    digital = 0;
    // 获取数字数组和运算符数组
    while('\0' != *p)
    {
        if(*p=='+' || *p=='-' || *p=='*' || *p=='/')
        {
            // list_digital用来放数字的数组，list_opr用来放运算符的数组
            list_digital[j] = digital;
            list_opr[i] = *p;
            i++;
            j++;
            digital = 0;
        }
        else if(isdigit(*p))
        {
            digital =  digital*10 + *p-'0';
        }
        p++;
    }
    // 最后一个数字保存
    list_digital[j] = digital;

    // 先把能做的乘法除法做掉
    for(i=0; i<num_opr; i++)
    {
        // 第i个符号对应第i、i+1个数字，乘除法做完后，第i个数字赋值INT_MIN，结果存在第i+1个，保证放在最后一个里面
        if((list_opr[i] == '*') || (list_opr[i] == '/'))
        {
            mul = (list_opr[i] == '*') ? (list_digital[i]*list_digital[i+1]) : (list_digital[i]/list_digital[i+1]);
            list_digital[i] = INT_MIN;
            list_digital[i+1] = mul;
            list_opr[i] = '0';
            k++;
        }
    }

    // k用来统计乘除运算符的个数，只有乘除的场景，返回最右侧的list_digital[i]
    if(num_opr<=k)
    {
        return list_digital[i];
    }

    // 再算加减
    for(i=0; i<num_opr; i++)
    {
        // 第i个符号对应第i、i+1个数字，但是由于之前做乘除法了，第i+1个可能为INT_MIN，所以先遍历一下，
        // 加减法做完后，第i个数字赋值INT_MIN，结果存在第i+1个，保证放在最后一个里面
        if((list_opr[i] == '+')||(list_opr[i] == '-'))
        {
            // +号左边的list_digital[i]肯定是有意义的，但list_digital[i+1]可能是连续的INT_MIN
            j = i+1;
            while(INT_MIN == list_digital[j]) j++;
            sum = (list_opr[i] == '+') ? (list_digital[i] + list_digital[j]) : (list_digital[i]-list_digital[j]);
            list_digital[i] = INT_MIN;
            list_digital[j] = sum;
        }
    }

    return list_digital[j];
}
```
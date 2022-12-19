4ms 76.32% 5.7 MB 100%

```
int* plusOne(int* digits, int digitsSize, int* returnSize){
    int i,carry=1;//carry表示进位,进位位赋初值为1即表示在原数字基础上+1
    int *result=NULL;//要返回的数组
    for(i=digitsSize-1;i>=0;i--){
        if(digits[i] == 9 && carry == 1){//当前位上的数字为9并且进位为1时，将当前位上的数字置为0，并且保持进位为1
            digits[i] = 0;
        }
        else{//如果运行到某一位上不是9，循环必然在这一位上停止（上一位产生的进位1加在这一位上面也不会再产生新的进位了）
        //设置进位为0，并且跳出循环。
            digits[i] = digits[i] + carry;
            carry = 0;
            break;
        }
    }
    result = (int*)malloc((digitsSize + carry)*sizeof(int));
    //循环结束，分配digitsSize+carry大小的空间给返回数组
    *returnSize = digitsSize + carry;
    if(carry == 1) result[0] = 1;//如果循环结束carry依然为1，说明在原数字最高位产生了进位，那么+1之后的数字最高位必然为1
    for(i=0;i<digitsSize;i++) result[i+carry]=digits[i];//将digits中的各个位复制到result中
    return result;
}
```

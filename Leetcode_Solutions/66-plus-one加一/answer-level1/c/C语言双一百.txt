### 解题思路
分三种情况
1.123456型(根本没有9) 
这种最简单，直接末尾加1即可
2.1234569型(只有最后一位是9)
最后一位如果等于9，那么需要从后往前遍历，对于遍历到的每一位如果是9，那么都置0，并且最前面9位的前一位加1
3.99999型(所有位都是9)
由2得出，但是需要判断首位是否为0，如果为0，开辟新数组写成100000 

### 代码

```c
int* plusOne(int* digits, int digitsSize, int* returnSize){
    int *arr = (int *)malloc(sizeof(int) * (digitsSize+1));
    if(digits[digitsSize-1]>=0 && digits[digitsSize-1]<9){
        digits[digitsSize-1] +=1;
        *returnSize = digitsSize;
        return digits;
    }
    else{
        int k = digitsSize-1;
        while(k>=0 && digits[k] == 9){
            digits[k] = 0 ;
            k--;
        }
        if(digits[0] == 0){
            
            arr[0] = 1;
            for(int i = 1 ; i <= digitsSize ;i++) arr[i] = 0 ;
            *returnSize = digitsSize+1;
            return arr;
        }else{
            digits[k] ++;
            *returnSize = digitsSize;
        }
    }
    return digits;
}
```
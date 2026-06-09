### 解题思路
当 A 的子数组 A[i], A[i+1], ..., A[j] 满足下列条件时，我们称其为湍流子数组：

若 i <= k < j，当 k 为奇数时， A[k] > A[k+1]，且当 k 为偶数时，A[k] < A[k+1]；
或 若 i <= k < j，当 k 为偶数时，A[k] > A[k+1] ，且当 k 为奇数时， A[k] < A[k+1]。
也就是说，如果比较符号在子数组中的每个相邻元素对之间翻转，则该子数组是湍流子数组。

返回 A 的最大湍流子数组的长度。

 

示例 1：

输入：[9,4,2,10,7,8,8,1,9]
输出：5
解释：(A[1] > A[2] < A[3] > A[4] < A[5])




注意这里i 是相对，  第一个字符可以是奇数也可以是偶数

### 代码

```c
#define MAX(a,b) ((a)>(b)?(a):(b))

int turbu(int* A, int ASize,int magic){
    int i=0,temp=1,max=1;
  
    for(i=0;i<ASize-1;i++){
        if((i+magic)%2){
            if(A[i] > A[i+1]){
                temp++;
            }else{
                max = MAX(max,temp); 
                temp=1;
            }
        }else{
            if(A[i]<A[i+1])
                temp++;
            else{
                max = MAX(max,temp); 
                temp=1;
            }
        }

    }

    return MAX(max,temp);//最后一个字符可能是符合的，就没有被统计，所以这里要统计比较下   
}

int maxTurbulenceSize(int* A, int ASize){
    
    int a = turbu(A,ASize,0);
    int b = turbu(A,ASize,1);

    return MAX(a,b);

}
```
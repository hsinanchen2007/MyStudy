如果数组末位（个位）小于 9 ，直接个位加 1 返回即可

如果数组末位（个位）等于 9，将该位（个位）设置为 0 ，并且产生了进位，接下来观察前一位（十位）

如果前一位（十位）小于 9 ，直接十位加 1 返回即可
如果前一位（十位）等于 9，将该位（十位）设置为 0 ，并且产生了进位，接下来观察前一位（百位）
以此类推，最后观察运算完的第一位是否为 0 ，如果为 0 ，则在最前面加 1 （示例 3）

```
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){
    int i;
   int *nums=(int*)malloc(sizeof(int)*(digitsSize+1));
   for(int i=digitsSize-1;i>=0;i--){
       if(digits[i]<9){
           digits[i]++;
           *returnSize=digitsSize;
           return digits;
       }
        digits[i]=0;
       
   }
   *returnSize=digitsSize+1;
   for(i=1;i<digitsSize+1;i++)
    nums[i]=0;
    nums[0]=1;
    return nums;
  
}
```
![image.png](https://pic.leetcode-cn.com/98cc0f411b7a57cf12bc895e3b32924bac915b747197ee0d69c59754fd77c05d-image.png)

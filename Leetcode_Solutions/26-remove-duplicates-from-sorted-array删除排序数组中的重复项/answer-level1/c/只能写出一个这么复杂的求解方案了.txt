### 解题思路
利用三重循环，然后逐个遍历，一直到结束。
这是最不费脑子，最笨的方法。
一会让还回去学习其他大神的方案。

### 代码

```c
int removeDuplicates(int* nums, int numsSize){
    int i,j,k;
    for(i=0;i<numsSize;i++){
        for(j=i+1;j<numsSize;j++){
            if(nums[i]==nums[j]){
                for(k=j;k<numsSize-1;k++){
                    nums[k]=nums[k+1]; 
                }
                numsSize-=1;
                j=j-1;
            }
        }
    }
    return numsSize;
}
```
###总结
1、numsSize-=1的位置最开始放在了k循环内部，这就出问题了。
2、第二次修改没有补充j=j-1，同样出问题了问题点在于当出现三次重复的时候会导致后面补充的元素直接跳过检测。
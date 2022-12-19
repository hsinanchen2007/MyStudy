### 解题思路
这个题和之前删除重复元素是一摸一样的思路甚至还更加简单。
就是循环找出相等的元素然后删掉，结束。

### 代码

```c
int removeElement(int* nums, int numsSize, int val){
    int i,j;
    for(i=0;i<numsSize;++i){
        if(nums[i]==val){
            for(j=i;j<numsSize-1;j++){
                nums[j]=nums[j+1];

            }
            numsSize-=1;
            --i;//第一轮写错了位置导致了死循环
        } 
      
    }
    return numsSize;
}
```

###总结
1、注意numsSize和i的变化要放在循环外面。不能放在循环里面。不然每次j变化的时候j都减受不了。
2、向着肝帝Knight看齐。
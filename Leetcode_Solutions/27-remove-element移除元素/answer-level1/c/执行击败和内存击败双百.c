### 解题思路
较简单的原地移除元素

### 代码

```c
int removeElement(int* nums, int numsSize, int val){
    int len=numsSize;//当前长度
    int i,j;
    for(i=0;i<len;i++){
        if(nums[i]!=val){
            continue;
        }
        else{
            for(j=i;j<numsSize-1;j++){
                nums[j]=nums[j+1];//移动，将当前等于val的元素覆盖
                
            }
            i--;//移动后，需要将i向前移动一个位置
            len--;//长度减小
        }
    }
    return len;
}
```
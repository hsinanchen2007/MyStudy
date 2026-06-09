### 解题思路
两个指针i和j，i走在前面，见到val相同的就跳过。
jump记录跳过数，返回数组长度用numssize-jump
要注意连续两个数组元素都等于val的情况，所以又加了一层for进行了处理

这个题代码短，思路清晰，可真正动手就是不好写，乱糟糟的。
把我胜率都拉低了。都跟被控住了一样，秀不起来。自己体会吧。
### 代码

```c


int removeElement(int* nums, int numsSize, int val){
    int i=0;int j=0;int jump=0;
    while(i<numsSize){
        if(nums[i]==val){
            int k;
            for(k=i;k<numsSize;k++){
                if(val==nums[k]){
                    i++;
                    jump++;
                }else{
                    break;
                }
            }
        }
        if(j>=numsSize||i>=numsSize){
            break;
        }
        nums[j]=nums[i];
        j++;i++;
    }
    return numsSize-jump;
}
```
### 解题思路
此题和“删除排序数组中的重复项”思想一样，都采用双指针来解决。
一个（慢）num指针为数组本身进行复写，一个（快）p指针不断移动并判断是否等于val的值。一旦快指针所指向的值不等于val，则进行复写，将快指针所指向的值复写慢指针所指向的值，且计数器加一。（注意顺序：先*nums=p[i]，后nums++；因为慢指针的最后一项总是待复写的位置，所以若快指针所指向的值不等于val时，先将快指针的值复写慢指针的值，再将慢指针往后挪一位）

### 代码

```c
int removeElement(int* nums, int numsSize, int val){
    int count=0;
    int *p=nums;
    for(int i=0;i<numsSize;i++){
        if(p[i]!=val){
            *nums=p[i];
            nums++;
            count++;
        }
    }
    return count;
}
```
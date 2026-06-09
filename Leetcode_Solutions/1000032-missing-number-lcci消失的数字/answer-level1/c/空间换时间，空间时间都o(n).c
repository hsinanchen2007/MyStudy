### 解题思路
![图片.png](https://pic.leetcode-cn.com/799b29446a8baf9e6b883cc97629ad43a05ece9cccd0c4a5d718ed94e67cbc1a-%E5%9B%BE%E7%89%87.png)
建一个数组，数组下标与nums数组中元素的值相对应。某数存在就标记为1，不存在标记为0

### 代码

```c
int missingNumber(int* nums, int numsSize){
    int res=0;
    int *a=(int*)malloc(sizeof(int)*(numsSize+1));
    for(int i=0;i<numsSize+1;i++){
        a[i]=0;
    }
    for(int i=0;i<numsSize;i++){
        int num=nums[i];
        a[num]=1;
    }
    for(int i=0;i<numsSize+1;i++){
        if(a[i]==0){
            return i;
        }
    }
    return res;
}
```
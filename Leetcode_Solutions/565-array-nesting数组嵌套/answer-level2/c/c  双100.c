![QQ截图20200312144359.png](https://pic.leetcode-cn.com/8ba3ea8b46bc618f996d3d8fd3c57bf8c180d39c3e594efb48fff51877853f35-QQ%E6%88%AA%E5%9B%BE20200312144359.png)

注意一下嵌套结束的条件是什么就行了
```
int arrayNesting(int* nums, int numsSize){
    int max=0,i,j,count=0,temp;
    for(i=0;i<numsSize;i++){
        for(j=i;nums[j]!=-1;){
            count++;
            temp=nums[j];
            nums[j]=-1;
            j=temp;
        }
        if(max<count){
            max=count;
        }
        count=0;
    }
    return max;
}
```

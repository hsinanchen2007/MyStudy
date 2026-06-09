### 解题思路

由于想错了，导致这个题目百思不得其解。

我刚开始把这个题目当作了二分查找的变体，“查找最后一个小于等给定值的元素”， 开开心心写代码，结果悲悲戚戚掉头发。

实际上，我们是查找第一个大于等于给定值的位置。我们以例3解释

```c
输入: [1,3,5,6], 7
输出: 4
```

1. low = 0, high = 3, mid = 1, nums[mid] =3,
2. 因为3小于7，更新low, low =2, high =3, mid=2, nums[mid]=5
3. 因为5小于7，更新low, low = 3, high =3, mid =3, nums[mid]=6
4. 因为6小与7, 更新low, low =4, high=3,退出循环
5. 退出循环后发现，找不到，那么low就是最后一个位置。

如果是示例 2:

```c
输入: [1,3,5,6], 2
输出: 1
```

1. low = 0, high = 3, mid = 1, nums[mid] =3,
2. 因为3大于2，更新high, high = mid - 1 =0, mid = 0, nums[mid]=1
3. 因为1小于2，那么开始分析mid的位置，因为mid在0，因此返回mid。

> 哎，想不通的时候就出去散散步呀，跳出自己的限制，否则受困于固定思维，只是死路一条。

### 代码

代码如下

```c

iint searchInsert(int* nums, int numsSize, int target){

    //查找第一个大于等于给定值的位置
    int low = 0;
    int high = numsSize - 1;
    int mid;
    while (low <= high){
        mid = low + ((high-low) >> 1);
        if ( nums[mid] >= target ){
            //如果在第一个位置，或者前一个位置就比target小
            //就说找到了
            if ( mid == 0 || nums[mid-1] < target){
                return mid;
            } else{ // 否则就是靠后了
               high = mid - 1;
            }
        } else{
            low = mid + 1;
        }
    }
    return low;

}



```
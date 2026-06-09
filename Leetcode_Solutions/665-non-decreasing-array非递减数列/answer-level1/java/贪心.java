### 解题思路
此处撰写解题思路
保证序列为非递减的，并且尽量保证后面的数组不受影响。
当nums[i]<nums[i-1]时，为保证后面的数尽量不受影响，这时改变nums[i-1]的值为nums[i],这时nums[i-1]=nums[i],并且后面的数组不受影响。但是，此时前面的数组可能因为nums[i-1]的改变形成了部分递增序列，此时只有num[i-1]的值改变了，所以受影响的只可能是nums[i-2]与nums[i-1]的大小关系，所以这时候我们不让nums[i-1]=nums[i]（因为nums[i]可能小于nums[i-2），我们直接让nums[i]=num[i-1],这种情况下可能会改变i之后的数组之间大小的关系,但因为我们是从前往后查找的，所以可以之后再对后面的元素进行调整。

### 代码

```java
class Solution {
    public boolean checkPossibility(int[] nums) {
        int num=0,i;
        for( i=1;i<nums.length;i++){
            if(nums[i]<nums[i-1]){
                num++;
                if(i-2>=0&&nums[i-2]>nums[i]) nums[i]=nums[i-1];
                else nums[i-1]=nums[i];
            }
        }
        return num<=1;
        
    }
}
```
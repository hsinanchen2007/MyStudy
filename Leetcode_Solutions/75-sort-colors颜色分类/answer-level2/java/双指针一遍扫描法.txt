### 解题思路
由于0必须从左往右依次排下去，2必须从右往左依次排下去。所以设置以下两种指针：
    `left`:下一个0必须放置的位置，即第一个不是0的数。
    `right`：下一个2必须放置的位置，即最后一个不是2的数。
显然初始`left`为`0`,`right`为`length-1`;
这样，从开始到结束依次遍历，开始算法：
    如果`nums[i]==0`且`i>=left`:
    1. 交换`nums[i]`与`nums[left]`的值;
    2. `left++`;
    3. 为了放置交换过来的`nums[left]`为0,必须再检查一下`i`，所以`i--`;  
    如果`nums[i]==2`且`i<=right`:
    1. 交换`nums[i]`与`nums[right]`;
    2. `right--`;
    3. 同样为了防止交换了2过来，必须`i--`;
这样，完成了0与2的布置，整个算法就完成了排序。
这里值得注意的一点是，为什么要加一个`i>=left`与`i<=right`的判定条件。这是由于防治将已经处于当前位置`i`上的`0`或者`2`给交换走了。
### 代码

```java
class Solution {
    public void sortColors(int[] nums) {
        if(nums.length==0||nums.length==1)return;
        
        int left=0,right=nums.length-1;
        for(int i=0;i<nums.length;i++)
        {
            if(nums[i]==0&&i>=left)
                swap(nums,i--,left++);
            else if(nums[i]==2&&i<=right)
                swap(nums,i--,right--);
        }
    }
    private void swap(int[] nums,int i,int j)
    {
        int temp=nums[i];
        nums[i]=nums[j];
        nums[j]=temp;
    }
}
```
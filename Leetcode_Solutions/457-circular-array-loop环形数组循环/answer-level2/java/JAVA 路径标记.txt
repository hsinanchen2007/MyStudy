### 解题思路
因为题目限定nums[i]小于1000，因此选一个大于1000的数作为路径数的标记

### 代码

```java
class Solution {
    public boolean circularArrayLoop(int[] nums) {
        if(nums.length <2)return false;
        int path = 5001;
        for(int i = 0;i<nums.length;i++){
            int tag = i;
            boolean right = false;
            if(nums[i]>0&&nums[i]<5000)right = true;
            if(nums[i]>5000)continue;
            int pre = Integer.MAX_VALUE;
            while((nums[tag]>0&&nums[tag]<5000&&right)||(nums[tag]<0&&!right)){
                int temp = nums[tag];
                nums[tag]=path;
                pre = tag;
                tag = tag+temp;
                while(tag>=nums.length)tag-=nums.length;
                while(tag<0)tag+=nums.length;
                if(tag == pre)break;
            }
            if(path == nums[tag] && (tag != pre))return true;
            path ++;
        }
        return false;
    }
}
```
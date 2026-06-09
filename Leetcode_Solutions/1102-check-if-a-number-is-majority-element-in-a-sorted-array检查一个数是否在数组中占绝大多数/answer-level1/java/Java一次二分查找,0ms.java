### 解题思路
找到该数字x第一次出现的位置pos，检查pos+n/2是否也是x。
注意target在数组中不存在的情况、pos+n/2越界的情况。

### 代码

```java
class Solution {
    public boolean isMajorityElement(int[] nums, int target) {
        int pos=findFist(nums,target);
        if(nums[pos]!=target){
            return false;
        }
        int n=nums.length;
        int right=pos+(n>>1);
        return right<n&&nums[right]==target;
    }
    private int findFist(int[] nums,int target){
        int left=0;
        int right=nums.length-1;
        while(left<right){
            int mid=((right-left)>>1)+left;
            if(nums[mid]>=target){
                right=mid;//mid及其左边都可能是答案
            }else{
                left=mid+1;
            }
        }
        return left;
    }
}
```
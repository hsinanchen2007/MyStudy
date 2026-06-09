![l.png](https://pic.leetcode-cn.com/abe8483200eb4bc971d14e699ff63bc61954eef28d590fa47ecf6ebce519cae0-l.png)


### 解题思路
用了数组的排序，不知还算不算O(n)。
排序后主要中间元素肯定是主要元素，然后从两端往中间挤，一直挤到不是中间元素的时候，看索引差是不是大于数组长度一半就可以了

### 代码

```java
class Solution {
    public int majorityElement(int[] nums) {
        if(nums==null||nums.length<=0){
            return -1;
        }
        Arrays.sort(nums);
        int middle=nums[nums.length/2];
        int left=0,right=nums.length-1;
        while(left<=right&&(nums[left]!=middle||nums[right]!=middle)){
            if(nums[left]!=middle){
                left++;
            }
            if(nums[right]!=middle){
                right--;
            }
        }
        return right-left+1>nums.length/2?middle:-1;
    }
}
```
### 解题思路
先找到最小值的index
然后判断target需要在什么区间寻找；target<=nums[len]
else l=0,r--
不能写成r=l-1...l已经变化了

### 代码

```java
class Solution {
    public int search(int[] nums, int target) {

        if(nums.length == 0) return -1;
        int l = 0, r = nums.length - 1;
        while(l < r)
        {
            int mid = (l + r) /2 ;
            if(nums[mid] <= nums[r]) r =mid;
            else l = mid + 1;
        }

        if(target <= nums[nums.length - 1]) r = nums.length - 1;
        else
        {
            l = 0;
            r--;
        }
        while(l < r)
        {
                int mid = (l + r) / 2;
                if(nums[mid] >= target) r = mid;
                else l = mid + 1; 
        }
        if(nums[l] == target) return l;
        return -1;

        
            
    
    }
}
```
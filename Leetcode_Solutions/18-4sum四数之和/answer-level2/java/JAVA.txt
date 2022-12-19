### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    List<List<Integer>> ans = new ArrayList<>();
    HashSet<Long> record = new HashSet<>();
    Long one,two,three;
    public List<List<Integer>> fourSum(int[] nums, int target) {     
        if(nums.length < 4) return ans;
        Arrays.sort(nums);
        one = 1L * nums.length;
        two = one * nums.length;
        three = two * nums.length;
        int i = 0,j = 1,m = nums.length-2,n = nums.length -1;
        find(nums,target,i,j,m,n);
        return ans;
    }
    private void find(int[] nums, int target,int i,int j,int m,int n){
        if(!(i < j &&  j < m && m < n)) return;
        Long index = i * three + j * two + m * one + n;
        if(record.contains(index)) return;else record.add(index);
        int value = nums[i] + nums[j] + nums[m] +nums[n];
        if(value == target){
            List<Integer> item = Arrays.asList(nums[i],nums[j],nums[m],nums[n]);
            boolean isAdd = true;
            for(List<Integer> list: ans){
                if(list.get(0) == nums[i] &&list.get(1) == nums[j]&&
                    list.get(2) == nums[m] &&list.get(3) == nums[n]){
                        isAdd = false;
                        break;
                    }

            }
            if(isAdd) ans.add(item);
        }
        if(value <= target){
            find(nums,target,i+1,j,m,n);
            find(nums,target,i,j+1,m,n);
        }else{
            find(nums,target,i,j,m-1,n);
            find(nums,target,i,j,m,n-1);
        }
    }
}
```
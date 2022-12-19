## 解题思路
* 采用回溯可以求子集之和等于K，但是无法解决子数组之和
* 题目要求O(n)采用递归不满足要求
* 被企业考过的题目

## 代码
```java []
//方案一、从C++算法改编过来
class Solution {
    
    public int maxSubArrayLen(int[] nums, int k) {
        int n = nums.length;
        int sum = 0;
        int ans = 0;
        Map<Integer,Integer> prefix = new HashMap<>();
        
        prefix.put(0,0);
        for(int i = 0;i < n; ++i){
            sum += nums[i];
            if(prefix.get(sum) == null){
                prefix.put(sum,i+1);
            }
            if(prefix.get(sum-k)!=null){
                ans = Math.max(ans,i + 1 - prefix.get(sum-k));
            }
        }
        
        return ans;
    }

}
```
```java []
//方案二、回溯算法，答案不正确
class Solution {
    int maxSize = 0;
    public int maxSubArrayLen(int[] nums, int k) {
        backtrack(nums,k,0,0,new ArrayList<>());
        return this.maxSize;
    }

    private void backtrack(int[] nums, int k, int index, int sum, List<Integer> tmpList) {        
        if(sum == k) {                        
            System.out.println(tmpList.toString());
            this.maxSize = Math.max(maxSize,tmpList.size());            
            return;
        }
        if( index >= nums.length ) {
            return;
        }
        for (int i = index; i < nums.length; i++) {
            tmpList.add(nums[i]);
            int tmpSum = sum + nums[i];
            backtrack(nums,k,i+1,tmpSum,tmpList);
            tmpList.remove(tmpList.size()-1);
        }
    }
}
```
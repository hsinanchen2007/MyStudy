### 解题思路
刚开始想到的是暴力法，明知道AC不了，还试了一下，最后两个测试用例，过不去。

看别人的双指针法挺好的
就是遍历一遍数组从k=0,到k=nums.length-3然后两支针i和j
i=k+1,j=nums.length-1.然后移动i和j向中间遍历。
在移动的过程中要记得要跳过重复的值，防止重复。

### 代码

```java
class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> list = new ArrayList<List<Integer>>();
        int i , j , k , length = nums.length;
        if(nums==null || length < 3)
        	return list;
        for(k = 0 ; k < length-2 ; k++){
        	if(nums[k]>0)
        		return list;;
        	if(k>0 && nums[k]==nums[k-1])
        		continue;
            i = k+1;
            j = length-1;
            
            while(i<j){
            	int s = nums[k]+nums[i]+nums[j];
            	if(s>0){
            		while(i<j && nums[j]==nums[--j]); // j-- 并且跳过相等的j
            	}else if(s<0){
            		while(i<j && nums[i]==nums[++i]); // i-- 并跳过相等的i
            	}else{
            		// =0的情况
            		// 因为是 k<i<j的情况所以
            		// Arrayx.asList(xxx,xxx,xxx)  转换成一个 list
            		list.add(new ArrayList<Integer>(Arrays.asList(nums[k],nums[i],nums[j])));
            		while(i<j && nums[j]==nums[--j]); // j-- 并且跳过相等的j
            		while(i<j && nums[i]==nums[++i]); // i-- 并跳过相等的i
            	}
            }
        }
        
        return list;
    }
}
```
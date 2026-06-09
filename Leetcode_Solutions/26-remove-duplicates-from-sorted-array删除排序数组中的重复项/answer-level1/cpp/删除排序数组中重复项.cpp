```
int removeDuplicates(vector<int>& nums) {
	if(nums.size() > 1){
        //dif_index记录最后一个不重复项的下标, cur_number记录最后一个不重复项的值
	    int dif_index = 0, cur_number = nums[0];
	    for(int i = 0; i < nums.size(); i++){
	    	if(nums[i] != cur_number){
	    		dif_index++;
	    		nums[dif_index] = nums[i];
	    		cur_number = nums[i];
			}
		}
        //将无用元素剔除
		for(int j = nums.size() - 1; j > dif_index; j--){
			nums.pop_back();
		}	
	}
	return nums.size();
}
```
![26.删除排序数组中重复项.png](https://pic.leetcode-cn.com/9713f91973818431329e85369bdc4bb70a6a24aa7c529e0a23677d237c9011e7-26.%E5%88%A0%E9%99%A4%E6%8E%92%E5%BA%8F%E6%95%B0%E7%BB%84%E4%B8%AD%E9%87%8D%E5%A4%8D%E9%A1%B9.png)

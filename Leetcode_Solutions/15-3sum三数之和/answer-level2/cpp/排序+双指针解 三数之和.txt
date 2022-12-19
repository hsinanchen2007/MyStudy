准备工作：

          排序，时间复杂度O(NlogN),相比暴力解法O(N^3)的复杂度，这点消耗还是非常值得的。

双指针思路：

           使用三个指针（k<i<j)。固定最小的k在左边，i=k+1,j=nums.size()-1。 移动两个指针包夹求解。
           保存使得nums[i]+nums[j]+nums[k]=0的解。偏大时j左移，偏小时i右移。i和j相遇时，表示以当前
           k为最小值的解已经全部求得。k++ 进入下一次循环。
解决重复解：

           上面的思路中可能存在重复解，原因是在i,j,k指针在移动时可能会出现重复数字的情况，比如：
            nums[i]==nums[i+1],这样的移动不考虑进去的话就会产生重复解。



时间复杂度： k指针遍历O(n)嵌套双指针i,j遍历O(n)  -->Ο(N^2)。
```
class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int> >res;   
        int _size=nums.size();    
        if(_size<3||nums.front()>0||nums.back()<0)
        return res;
        int i,j,k;
        for(k=0;k<=_size-3;k++){
        	if(nums[k]>0)
        	    break;
        	if(k>0&&nums[k]==nums[k-1])
        		continue;                               //跳过无意义移动
        	i=k+1;j=_size-1;
        	while(i<j){
        		if(nums[i]+nums[j]+nums[k]>0)
        		    j--;
        		else if(nums[i]+nums[j]+nums[k]<0)
        		    i++;
        		else{
        			res.push_back({nums[i],nums[j],nums[k]});
        			while(i<j&&nums[i]==nums[i+1])      //跳过无意义移动
        			    i++;
        			while(i<j&&nums[j]==nums[j-1])      //同上
        			    j--;
        			i++;
        			j--;           //这里可以两边同时缩近，缩一边没啥用hahaha。
				}
			}
		}
		return res;
    }
};
```

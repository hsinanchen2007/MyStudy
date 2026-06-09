### 解题思路
此处撰写解题思路
//思路:利用滑动窗口队列的思路，对于这种连续的子问题
//先从右边滑入一个新的数据，然后计算这个和，如果这个和>之前的记录，那么就更新
//然后对于新滑入数据后的这个子数组，我们需要继续从左侧尝试滑出一些数据，看能否产生一个最大的子数组和，然后记录下来这个和
//如果新的窗口中的数组>之前的所有记录，更新结果
### 代码

```cpp
//思路:利用滑动窗口队列的思路，对于这种连续的子问题
//先从右边滑入一个新的数据，然后计算这个和，如果这个和>之前的记录，那么就更新
//然后对于新滑入数据后的这个子数组，我们需要继续从左侧尝试滑出一些数据，看能否产生一个最大的子数组和，然后记录下来这个和
//如果新的窗口中的数组>之前的所有记录，更新结果
class Solution {
public:
   int maxSubArray(vector<int>& nums) {
	if(nums.size()==0){
		return 0;
	}
	int sum_max=0;
	int sub_max=0;
	std::vector<int> sub_nums;
	for (auto iter=nums.begin();iter<nums.end();iter++)
	{
		if(sub_nums.empty()){
			sub_nums.push_back(*iter);
			sum_max=*iter;
			sub_max=*iter;
			continue;
		}
		//先滑入一个最新的数据进来
		cout<<"last sub_max:"<<sub_max<<endl;
		sub_nums.push_back(*iter);
		int sum = sub_max + *iter;
		if(sum > sum_max){
			sum_max = sum;
		}
		sub_max = sum;
		cout<<"update sum:"<<sum<<endl;
		//然后计算移出左侧的数据以后，是否可以让子数组的和达到最大值
		for (std::vector<int>::iterator iter_sub = sub_nums.begin(); iter_sub != sub_nums.end()-1;)
		{
			sum=sum-*iter_sub;
			if(sum>sub_max){//这种情况直接移出左侧的这个数据
				sub_max=sum;
				cout<<"sub_max:"<<sub_max<<endl;
				iter_sub=sub_nums.erase(sub_nums.begin(),++iter_sub);
			}else{
				iter_sub++;
			}
		}
		cout<<"**sub_nums size:"<<sub_nums.size()<<endl;
		if(sub_max>sum_max){
			sum_max=sub_max;
		}
	}
	return sum_max;	
}
};
```
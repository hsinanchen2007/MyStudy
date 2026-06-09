### 解题思路
开辟map存储原始ele以及times
建立vector存储上述map，并且进行排序
### 代码

```cpp
class Solution {
public:
	vector<int> topKFrequent(vector<int>& nums, int k){
		vector<int> vec_topK;
		map<int, int> nums_times;
		for(size_t i=0;i<nums.size();++i){
			nums_times[nums[i]]++;
		}
//		//for debug
//		cout << "ele" << setw(3) << " times" << endl;
//		for(auto& iter:nums_times){
//			cout << iter.first << setw(5) << iter.second << endl;
//		}
		vector<pair<int, int>> sorted_nums(nums_times.begin(), nums_times.end());
		std::sort(sorted_nums.begin(), sorted_nums.end(), [](const pair<int, int>& l, const pair<int, int>& r){
			return l.second > r.second;
		});
		for(int i=0;i<k;++i){
			vec_topK.push_back(sorted_nums[i].first);
		}

		return vec_topK;
	}
/*
    vector<int> topKFrequent(vector<int>& nums, int k) {
    	if(nums.size() == 1) return nums;
    	vector<int> vec_k_freq;
    	sort(nums.begin(), nums.end());

    	int times = 0;
    	size_t i = 0;
    	while(nums.size() > 1)
    	{
    		if(nums[i] != nums[0]){
    			if(times >= k){
    				vec_k_freq.push_back(nums[0]);//push last topK element
    				times = 0;
        			for(size_t j=0;j<i;++j){
        				nums.erase(nums.begin());
        			}
        			i = 0;
    			}
    		}
    		else{
    			if(nums.size() == 1) return vec_k_freq;
    			times++;
    			i++;
    			if(i >= nums.size()){
    				vector<int> vec;
    				vec.push_back(nums[i-1]);
    				return vec;
    			}
    		}
    	}//for

    	return vec_k_freq;
    }*/
};
```
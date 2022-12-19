### 解题思路
### 代码

```cpp
class Solution {
public:
    int nthUglyNumber(int n){
    	int i2 = 0;
    	int i3 = 0;
    	int i5 = 0;
    	vector<int> ugly_nums = {1};
    	int num_found = 1;
    	while(num_found < n)
    	{
    		int candidate = std::min(2*ugly_nums[i2], std::min(3*ugly_nums[i3], 5*ugly_nums[i5]));
        	if(candidate == 2*ugly_nums[i2]) i2++;
        	else if(candidate == 3*ugly_nums[i3]) i3++;
        	else i5++;
//        	cout << "i="<<num_found<<" ugly_num="<<candidate<<" i2="<<i2<<" i3="<<i3<<" i5="<<i5<<endl;
    		if(candidate > ugly_nums.back()){
            	ugly_nums.push_back(candidate);
            	num_found++;
    		}
    	}
    	return ugly_nums.back();
    }
};
```
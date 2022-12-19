```
代码块
int threeSumClosest(vector<int>& nums, int target) {
        int result = nums[0]+nums[2]+nums[1];
    sort(nums.begin(), nums.end());
    for(auto i = nums.begin(); i!=nums.end(); ++i){
        auto L = i+1;
        auto R = nums.end()-1;
        int sum;
        while(L<R){
            sum = *i + *L + *R;
            if(abs(sum-target)<abs(result-target))
                result = sum;

            if(sum>target)   R--;
            else if(sum<target)   L++;
            else{
                return sum;
            }
        }
    }
    return result;
    }
```cpp

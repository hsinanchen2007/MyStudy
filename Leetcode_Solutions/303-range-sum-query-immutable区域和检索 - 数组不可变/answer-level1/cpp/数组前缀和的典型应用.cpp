题目已经很清楚地暗示使用前缀和了

```cpp
class NumArray 
{
private:
    vector<int> cnt;        //存储数组前缀和
public:
    NumArray(vector<int>& nums) 
    {
        if(!nums.empty())
        {
            cnt.push_back(nums[0]);
            for(int i = 1; i < nums.size(); ++i)
            {
                nums[i] += nums[i-1];
                cnt.push_back(nums[i]);
            }
        }
    }
    
    int sumRange(int i, int j) 
    {
        return (i == 0) ? cnt[j] : cnt[j] - cnt[i-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
```
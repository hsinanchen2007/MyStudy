### 解题思路
复杂度为O(n)

### 代码

```cpp
class MaxQueue {
public:
    MaxQueue() {
    }
    
    int max_value() {
        if(maximums.empty()) return -1;
        return maximums.front().number;
    }
    
    void push_back(int value) {
        while(!maximums.empty()&&value>=maximums.back().number)
            maximums.pop_back();
        InternalData internalData={value,currentIndex};
        data.push_back(internalData);
        maximums.push_back(internalData);
        ++currentIndex;
    }
    
    int pop_front() {
        if(maximums.empty()) return -1;
        if(maximums.front().index==data.front().index)
            maximums.pop_front();
            int ans=data.front().number;
            data.pop_front();
        return ans;
    }
private:
    struct InternalData{
        int number;
        int index;
    };
    deque<InternalData> data;
    deque<InternalData> maximums;
    
    int currentIndex;
};
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        if(nums.size()<k||k<1) return ans;
        MaxQueue mx;
        for(int i=0;i<k;++i){
            mx.push_back(nums[i]);
        }
        for(int i=k;i<nums.size();++i){
            ans.push_back(mx.max_value());
            mx.pop_front();
            mx.push_back(nums[i]);
        }
        ans.push_back(mx.max_value());
        return ans;
    }
};
```
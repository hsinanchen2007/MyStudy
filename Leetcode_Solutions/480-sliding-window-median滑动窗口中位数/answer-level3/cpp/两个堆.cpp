### 解题思路

一个大根堆，一个小根堆。

### 代码

```cpp
class Solution {
private:
    priority_queue<int> lo;
    priority_queue<int, vector<int>, greater<int>> hi;
    unordered_map<int, int> dict;
    vector<double> medians;
    int balance = 0;
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0;
        
        // build window
        while(i < k) {
            lo.push(nums[i++]);
            balance++;
        }
        int j = k / 2;
        while(j--) {
            hi.push(lo.top());
            lo.pop();
        }
        
        double median;
        int l = 0;
        int r = k;
        while(true) {
            // save median
            if(k % 2)
                median = lo.top();
            else
                median = ((double)lo.top() + (double)hi.top()) / 2.0;
            medians.push_back(median);
            balance = 0;
            
            if(r >= n)
                break;
            
            // slide window
            int out = nums[l++];
            int in = nums[r++];
            
            // Dequeue
            if(out <= lo.top()) {
                balance--;
            } else {
                balance++;
            }
            dict[out]++;
            
            // Enqueue
            if(in <= lo.top()) {
                lo.push(in);
                balance++;
            } else {
                hi.push(in);
                balance--;
            }
            
            // rebalance
            rebalance();
            
            // Clean invalid numbers removed before
            while(!lo.empty() && dict[lo.top()] > 0) {
                dict[lo.top()]--;
                lo.pop();
            }
            while(!hi.empty() && dict[hi.top()] > 0) {
                dict[hi.top()]--;
                hi.pop();
            }
        }
        return medians;
    }
    
    void rebalance() {
        // 调整，若 lo.size() > hi.size() + 1
        if(!lo.empty() && balance > 0) {
                hi.push(lo.top());
                lo.pop();
                balance--;
        }
        
        // 调整，若 hi.size() > lo.size()
        if(!hi.empty() && balance < 0) {
                lo.push(hi.top());
                hi.pop();
                balance++;
        }
    }
};
```
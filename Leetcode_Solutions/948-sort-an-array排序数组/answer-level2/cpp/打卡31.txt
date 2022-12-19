### 解题思路
  双重for肯定超时，sort我没试过。但是我觉得简单题可能还会用sort，既然是中等题，我一般都是用自己写的。而且，能力有限。快排、堆排序这些都不太会用。只能用简单的。
  每次去存放数字，如果这个数是小于第一个，那就放到头里去，如果大于最后一个，就放到末尾。否则，就用二分搜到该放的位置放进去。这样时间好歹是nlogn左右。没想到过了，还需努力啊。

### 代码

```cpp
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        vector<int> r;
        int n = nums.size();
        if(n <= 1)return nums;
        r.push_back(nums[0]);
        int l = 0;
        for(int i = 1 ; i < n ; i++){
            if(nums[i] >= r[l]){
                r.push_back(nums[i]);
                l++;
            }
            else if(nums[i] <= r[0]){
                l++;
                r.insert(r.begin() , nums[i]);
            }
            else{
                int t = l;
                int f = 0;
                while(f <= t){
                    int mid = (f + t) / 2;
                    if(r[mid] < nums[i])f = mid + 1;
                    else t = mid - 1;
                }
                r.insert(r.begin() + f , nums[i]);
                l++;
            }
        }
        return r;
    }
};
```
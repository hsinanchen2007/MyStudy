### 解题思路
首先在nums前面插入一个0，使得我们可以从1到N进行遍历，并且把i放到nums[i]的位置上。
然后从st=1开始往后遍历，直接见代码。

为啥最终内存消耗是5%呢？难道就是因为前插了个0？？

那我再试试nums.push_back(0), 然后swap(nums[0], nums[n])试试

### 代码

```cpp
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int N = nums.size();
        vector<int> ans;
        nums.insert(nums.begin(), 0);
        int st = 1;
        while(st <= N){
            if(st == nums[st]) st++;
            else{
                int k = nums[st];
                if(nums[k] == -1){
                    nums[k] = k;
                    nums[st] = -1;
                    st++;
                }else if(k == nums[k]){
                    ans.push_back(k);
                    nums[st] = -1;
                    st++;
                }else{
                    nums[st] = nums[k];
                    nums[k] = k;
                }
            }
        }
        return ans;
    }
};
```
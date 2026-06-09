```
class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int>res;
        int len = nums.size();
        for(int i = 0; i < len/2; i++){
            int a = nums[2*i];
            int b = nums[2*i + 1];
            for(int j = 0; j < a; j++){
                res.push_back(b);
            }
        }
        return res;
    }
};
```
![1.png](https://pic.leetcode-cn.com/24ca5d9bfcb10139ace11d4fb05209609dee3950a9de5eb9665fc379827823e1-1.png)

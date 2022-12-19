```
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        if(arr.size() == 1){
            return true;
        }
        int nums[2001] = {0};
        for(int i = 0;i < arr.size(); i++){
            nums[arr[i] + 1000]++;
        }
        sort(nums, nums + 2001);
        for(int i = 0;i < 2000; i++){
            if(nums[i] == nums[i + 1] && (nums[i] != 0 && nums[i + 1] != 0)){
                return false;
            }
        }
        return true;
    }
};
```
![微信截图_20191207130851.png](https://pic.leetcode-cn.com/d9f3c589cf38229a3431aac3e419f5de14943256c5a17908233f8cf873972e99-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20191207130851.png)

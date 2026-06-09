利用双指针，一个指针找到最后一个奇数的位置lastOd，一个指针找到第一个偶数位置firstEv，并交换firstEv~lastOd下标之间的数字nums[firstEv]~nums[lastOd]
时间复杂度为O(N),空间复杂度O(N).

```
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int lastOd , firstEv;
        vector<int> res(nums);
        for(int i=0;i < nums.size();i++){
            if(nums[i] & 1) {
                lastOd = i;
                break;
            }
        }
        for(int i=0;i < nums.size();i++){
            if(!(nums[i] & 1)) {
                firstEv = i;
                break;
            }
        }
        if(lastOd > firstEv){
            int tmp = res[lastOd];
            for(int i=lastOd;i > firstEv;i--){
                res[i] = res[i-1];
            }
            res[firstEv] = tmp;
            tmp = lastOd;
            lastOd = firstEv;
            firstEv = firstEv + 1;
        }
        for(int i=0;i < res.size();i++){
            if(res[i] & 1){
                lastOd = i;
                if(lastOd > firstEv){
                    int tmp = res[lastOd];
                    for(int i=lastOd;i > firstEv;i--){
                        res[i] = res[i-1];
                    }
                    res[firstEv] = tmp;
                    tmp = lastOd;
                    lastOd = firstEv;
                    firstEv = firstEv + 1;
                }
            }
        }
        return res;
    }
};
```

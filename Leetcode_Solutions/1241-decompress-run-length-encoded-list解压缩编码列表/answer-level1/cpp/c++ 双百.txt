![image.png](https://pic.leetcode-cn.com/d98ad3d02bcea7c6a3b42954c3be21f8367af02774c700793cbadf96c382ece0-image.png)


```
class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        int len = (int)nums.size();
        vector<int> ret;
        if(!len) return ret;
        int index = 0;
        while(index < len-1){
            for(int i = 0; i<nums[index]; i++){
                ret.push_back(nums[index+1]);
            }
            index += 2;
        }
        return ret;
    }
};
```

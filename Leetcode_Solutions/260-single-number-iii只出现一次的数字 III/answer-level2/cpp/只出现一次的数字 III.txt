### 解题思路
异或分开数组

### 代码

```cpp
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int tmp = 0;
        for(int i = 0; i < nums.size(); ++i) {
            tmp = tmp ^ nums[i];
        }
        cout<<tmp<<endl;
        int bit = 1;
        while((tmp & 1) == 0) {
            tmp = tmp >> 1;
            bit = bit << 1;
        }
        cout<<bit<<endl;
        int tmp1 = 0;
        int tmp2 = 0;
        for(int i = 0; i < nums.size(); ++i) {
            if ((nums[i] & bit) == 0) {
                //cout<<"1: "<<nums[i]<<endl;
                tmp1 = tmp1 ^ nums[i];
            } else {
                //cout<<"2: "<<nums[i]<<endl;
                tmp2 = tmp2 ^ nums[i];
            }
        }
        vector<int> res;
        res.push_back(tmp1);
        res.push_back(tmp2);
        return res;
    }
};
```
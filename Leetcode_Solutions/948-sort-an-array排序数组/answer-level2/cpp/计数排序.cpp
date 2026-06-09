### 解题思路
此处撰写解题思路
开辟一个数组，保证能存下所有的数，然后记录每个数的次数，因为有负数，即存数时加上最小数的相反数；
然后再遍历整个数组，从小到大，存的数减去刚刚加的数即可
### 代码

```cpp
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int num[100010] = {0};
        int len = nums.size();
        vector<int>res;
        for(int i = 0; i < len; i++){
            num[nums[i] + 50000]++;
        }
        int index = 0;
        for(int i = 0; i < 100010; i++){
            for(int j = 0; j < num[i]; j++){
                res.push_back(i - 50000);
            }
        }
        return res;
    }
};
```
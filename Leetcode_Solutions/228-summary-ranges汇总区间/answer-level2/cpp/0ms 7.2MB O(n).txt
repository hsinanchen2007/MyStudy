### 解题思路
一直报范围溢出的错误。。。。不过解决了
0ms，7.2MB

### 代码

```cpp
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        char ch[50];
        int temp;
        for (int i = 0; i < nums.size(); i++) {
            temp = i;
            while(i < nums.size() - 1 && nums[i + 1] - 1 == nums[i]) i++;
            if (temp != i) {
                sprintf(ch, "%d->%d", nums[temp], nums[i]);
                res.push_back(ch);
            } else {
                sprintf(ch, "%d", nums[temp]);
                res.push_back(ch);
            }
        }
        return res;
    }
};
```
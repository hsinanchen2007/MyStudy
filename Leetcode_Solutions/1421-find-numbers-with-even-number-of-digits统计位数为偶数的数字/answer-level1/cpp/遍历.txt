### 解题思路


### 代码

```cpp
class Solution {
private:
    bool isDouble(int num){
        int cnt = 0;
        while(num) num /= 10,cnt++;
        return cnt % 2 == 0 ? true : false;
    }
public:
    int findNumbers(vector<int>& nums) {
        int cnt = 0;
        for(int i = 0;i < nums.size();i++)
            cnt += isDouble(nums[i]);
        return cnt;
    }
};
```
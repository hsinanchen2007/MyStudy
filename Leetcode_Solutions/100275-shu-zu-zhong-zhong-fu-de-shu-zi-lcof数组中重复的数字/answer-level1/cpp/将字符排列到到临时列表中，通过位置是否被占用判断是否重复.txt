### 解题思路
发现使用map效率并没有比vector更高，可能是因为map的insert太耗时。
vector的at(i)方法比[i]效率高一些。

### 代码

```cpp
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int len = nums.size();
        int ret = -1;
        vector<int> vecDic(len, -1);
        for (int i = 0; i < len; i++) {
            int val = nums.at(i);
            if(vecDic.at(val) == -1) {
                vecDic[val] = val;
            } else {
                ret = val;
                break;
            }
        }
        return ret;
    }
};
```
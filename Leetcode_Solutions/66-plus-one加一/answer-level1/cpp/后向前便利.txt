### 解题思路
此处撰写解题思路
https://leetcode-cn.com/problems/plus-one/solution/yi-ci-bian-li-xiang-tong-codesi-ci-ti-jiao-zui-jia/
### 代码

```cpp
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int size = digits.size();
        for(int i = size - 1; i >= 0; --i){
            if(digits[i] < 9){
                ++digits[i];
                return digits;
            }
            if(i == 0){
                digits[i] = 1;
                digits.push_back(0);
            }
            else
                digits[i] = 0;
        }
        return digits;
    }
};
```
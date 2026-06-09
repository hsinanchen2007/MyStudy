### 解题思路
1.根据k的数字，从数组后截取数组内容，若k值大于数组大小则取余在做截取。

### 代码

```cpp
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(k > nums.size()){
            k %= nums.size();
        }
        vector<int> temp(nums.end() - k,nums.end());
        nums.erase(nums.end() - k,nums.end());
        nums.insert(nums.begin(),temp.begin(),temp.end());
    }
};
```
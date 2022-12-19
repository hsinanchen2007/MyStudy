### 解题思路
方法1：抽屉原理+换位trick
方法2：异或法
### 方法1

```cpp
class Solution {
public:
    vector<int> missingTwo(vector<int>& nums) {
        int full_size = nums.size() + 2;
        vector<int> ans;
        nums.push_back(0);
        nums.push_back(0);
        for (int i = 0; i < full_size; i++) {
            while (nums[i] != i + 1 && nums[i] != 0) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        for (int i = 0; i < full_size; i++) {
            if(nums[i] == 0) {
                ans.push_back(i + 1);
            }
        }
        return ans;
    }
};
```
### 方法2

```cpp
class Solution {
public:
    vector<int> missingTwo(vector<int>& nums) {
        //用异或法找出两个缺少的数字的异或运算结果
        int _xor = 0, inc_num = 0;
        for (auto number : nums) {
            _xor ^= number;
            _xor ^= ++inc_num;
        }
        _xor ^= ++inc_num;
        _xor ^= ++inc_num;
        //现在_xor为缺少的两个数字的异或结果
        int diff = _xor & (-_xor);
        //这里的diff是找出_xor的二进制最右位的1，也就是缺少的两个数字的二进制的最右位不同
        //这里需要复习下补码的内容，所有位取反加1
        //这样就可以将原数组分开进行异或，思考为啥可以求出
        int _xor_1 = 0;
        inc_num = 0;
        //再次用异或法找出其中一个数字
        for (auto number : nums) {
            if ((number & diff) != 0) {
                _xor_1 ^= number;
            }
            if ((++inc_num & diff) != 0) {
                _xor_1 ^= inc_num;
            }
        }
        if ((++inc_num & diff) != 0) {
            _xor_1 ^= inc_num;
        }
        if ((++inc_num & diff) != 0) {
            _xor_1 ^= inc_num;
        }
        //通过两个缺少的数字的异或运算结果对其中一个数字进行异或即可得到另一个数字
        return vector<int>{_xor_1, _xor ^ _xor_1};
    }
};
```

```cpp
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        std::rotate(nums.begin(), nums.end() - k % nums.size(), nums.end());
    }
};
```
- 直接调用<algrorithm>中的函数，函数原型可参考[这篇博客](https://blog.csdn.net/li1615882553/article/details/83546763)
```cpp
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        reverse(nums.begin(), nums.end() - k % nums.size());
        reverse(nums.end() - k % nums.size(), nums.end());
        reverse(nums.begin(), nums.end());
    }
};
```
- 三重反转
- 把一个数组的右边一部分移动到左边相当于：
	- 把左部分翻转
	- 把右部分翻转
	- 最后把整体翻转
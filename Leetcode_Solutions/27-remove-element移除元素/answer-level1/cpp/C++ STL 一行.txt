如题，只是为了介绍一下STL还有个这种东西。
执行用时 :4 ms, 在所有 C++ 提交中击败了 73.70% 的用户
内存消耗 :6.5 MB, 在所有 C++ 提交中击败了 100.00% 的用户
```
int removeElement(vector<int>& nums, int val) {
        return distance(nums.begin(),partition(nums.begin(),nums.end(),[=](const int& a){return a != val;}));
    }
```

```
class Solution {
public:
    int massage(vector<int>& nums) {
        vector<int> count(nums.size()+2, 0);
        for (int i = 0; i < nums.size(); i++) count[i+2] = max(count[i] + nums[i], count[i+1]);
        return count[nums.size() + 1];
    }
};
```
执行用时 : 4 ms, 在所有 C++ 提交中击败了63.53%的用户
内存消耗 :7.7 MB, 在所有 C++ 提交中击败了100.00%的用户

但上述方法中初始化vector耗了4毫秒，不仅浪费时间，大多数计算结果也用不上。如果你不关心中间结果，只需要稍微改进一下：
```
class Solution {
public:
    int massage(vector<int>& nums) {
        int a=0,b=0;
        for (int i = 0; i < nums.size(); i++) {int c = max(a + nums[i], b); a = b; b = c;}
        return b;
    }
};
```

执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗 :7.7 MB, 在所有 C++ 提交中击败了100.00%的用户

![QQ截图20200324175325.png](https://pic.leetcode-cn.com/93fc6660b0400bf06be59fea22d0bdfd25f1a22a4cbb510f528999e093536e96-QQ%E6%88%AA%E5%9B%BE20200324175325.png)


非常完美！


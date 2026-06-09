![image.png](https://pic.leetcode-cn.com/3f1543e4e4a3c9ea46765935dd1de85489ed3c699b5f2f50653e8667f51e4b4c-image.png)

### 解题思路
主要记录一下自己对于cmp语法的理解。
- cmp需要加static

### 重难点是两个参数a和b
- 对于sort函数而言，若cmp返回真，则会将cmp的第一个参数放在左边，若cmp返回假，则会将cmp的第二个参数放在左边。
- 所以cmp需要做的就是，让sort函数知道，对于a和b这两个不同的待比较对象而言，应该把谁放在左边，把谁放在右边。
- 在本题中，a和b是两个字符串，比如a是“30”，b是“33”，那么排序的时候是把“30”放左边，还是把“33”放左边？让cmp来决定。cmp的逻辑是，如果把a放前面得到的数要小一点，也就是a+b要比b+a小一点，那就把第一个参数a放左边，否则就把第二个参数b放左边。

### 代码

```cpp
class Solution {
static bool cmp(string a, string b){
    return a+b < b+a;
}

public:
    string minNumber(vector<int>& nums) {
        vector<string> vecString;
        for(int i=0; i<nums.size(); i++){
            vecString.push_back(to_string(nums[i]));
        }
        sort(vecString.begin(), vecString.end(),cmp);
        string res;
        for(auto s : vecString){
            res += s;
        }
        return res;
    }
};
```

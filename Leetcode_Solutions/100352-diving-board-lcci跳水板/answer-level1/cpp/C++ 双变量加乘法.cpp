### 解题思路
shorter的个数一个一个慢慢变少至0，longer的个数从0开始慢慢变多，
关键代码：shorter*i + longer*(j);
重复的数是不可以加进去的，所以在加入新的数之前，先和上一个加入的数比较一下，
不相同再加入。

也差不多双百了，还行吧

### 代码

![image.png](https://pic.leetcode-cn.com/b25a4efc79260cd0a3f24c305948e29e962243ca7e83abf40fd64486bc605800-image.png)


```cpp
class Solution {
public:
    vector<int> divingBoard(int shorter, int longer, int k) {
        vector<int> ivec;
        if(k==0) return ivec;
        int temp, comp;
        for(int i = k, j = 0; i >= 0 ; i--, j++){
            comp = shorter*i + longer*(j);
            if(comp != temp) ivec.push_back(comp);
            temp = comp;
        }
        return ivec;
    }
};

```
### 解题思路
这审判机制闪瞎我的双眼！！！！
![64TQJVD(T`LHLI{A\](8{_~W.png](https://pic.leetcode-cn.com/e5282e2ace5e3d85ee1d8c6a47d5197fa88eb42853171629759766ddb6f4b8ed-64TQJVD\(T%60LHLI%7BA%5D\(8%7B_~W.png)

### 代码

```cpp
class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;
        for(int i=left;i<=right;i++)
        {
            if(judge(i))
                res.push_back(i);
        }
        return res;
    }
    bool judge(int i)
    {
        int n=i;
        while(i)
        {
            int temp=i%10;
            if(temp==0 || n%temp!=0)
                return false;
            i=i/10;
        }
        return true;
    }
};
```
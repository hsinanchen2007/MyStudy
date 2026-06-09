### 解题思路


### 代码

```cpp
class Solution {
public:

    //1、递归解法  超出时间限制
    int tribonacci(int n) {
        
        if(n == 0)
        {
            return 0;
        }
        else if(n == 1 || n == 2)
        {
            return 1;
        }
        else
        {
            return tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);
        }
    }

    //2、迭代解法
    int tribonacci(int n) {

        //使用一个数组 记录下前面已计算出的泰波那契数
        vector<int> v(38);
        v.at(0) = 0;
        v.at(1) = 1;
        v.at(2) = 1;

        for(int i = 3; i <= n; ++i)
        {
            v.at(i) = v.at(i - 1) + v.at(i - 2) + v.at(i - 3);
        }

        return v.at(n);
    }
};
```
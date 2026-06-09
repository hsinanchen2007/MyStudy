### 解题思路

使用一个long保存宝石标记
然后利用位运算 

![image.png](https://pic.leetcode-cn.com/b8bf9b79952428cfb9bef75a044b485bea0409494e48b0d106e4fc8cad10cb8e-image.png)

### 代码

```cpp
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        long flag = 0;
        for(int i = 0; i< J.size(); i++)
        {
            int temp = J[i] - 'A' + 1;
            //cout<<temp<<" "<<J[i]<<endl;
            flag |= (long)1<<temp;
        }
        int count = 0;
        for(int i = 0; i< S.size(); i++)
        {
            int temp = S[i] - 'A' + 1;
            if((((long)1<<temp) & flag) != 0)
                ++count;
            
        }
        return count;
    }
};
```
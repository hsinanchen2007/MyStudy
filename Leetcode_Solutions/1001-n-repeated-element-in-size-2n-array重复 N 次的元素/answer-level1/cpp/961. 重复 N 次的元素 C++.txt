### 解题思路

### 代码

```cpp
class Solution {
public:
    int repeatedNTimes(vector<int>& A) {

        //在大小为 2N 的数组中有 N+1 个不同的元素，其中有一个元素重复了 N 次
        //表明：其他的元素都没有重复
        //则只要在计数的过程中找到 次数 == 2 就停止 即为该元素
        vector<int> v(10000);

        for(int i = 0; i < A.size(); ++i)
        {
            if(v.at(A.at(i)) == 1) //先判断 已经为1，则没必要再加了
            {
                return A.at(i);
            }

            ++v.at(A.at(i));
        }

        return 0;
    }
};
```
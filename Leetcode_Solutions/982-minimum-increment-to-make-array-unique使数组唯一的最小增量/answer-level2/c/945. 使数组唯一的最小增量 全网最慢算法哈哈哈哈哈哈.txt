### 解题思路
执行用时 :
2080 ms, 在所有 C++ 提交中击败了5.26%的用户
内存消耗 :25.9 MB, 在所有 C++ 提交中击败了20.83%的用户
哈哈哈哈哈这么差的数据我就不教大家啦小弟是辣鸡
### 代码

```cpp
class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        if(A.size() == 0)
            return 0;

        int nums [50100];
        for(int i = 0 ; i < 50100; i++)
            nums[i] = 0;
        
        for(int i = 0 ; i < A.size(); i++)
            nums[A[i]]++;
        
        int move = 0;
        for(int i = 0 ; i < A.size(); i++)
            if(nums[A[i]] != 1)
            {
                for(int j = A[i]; j < 50100; j++)
                    if(nums[j] == 0)
                    {
                        move += j - A[i];
                        nums[A[i]]--;
                        nums[j] = 1;
                        break;
                    }
            }

        return move;
    }
};
```
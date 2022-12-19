执行结果：通过 显示详情
执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗 :8.3 MB, 在所有 C++ 提交中击败了100.00%的用户
```
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int zeros = stones.size();
        while(zeros > 1)
        {
            sort(stones.rbegin(), stones.rend());
            if(stones[1] == 0)
                break;
            stones[0]-=stones[1];
            stones[1]-=stones[1];
        }
        return stones[0];
    }
};

```
### 解题思路
其实很简单。
1. 排序
2. 判断末尾的石头是否相等，是的话全部pop，但是i需要-1，因为相当于做了两次循环。不相等就按题目要求pop一个。
3. 重新排序
4. 循环处理

### 代码

```cpp
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int len=stones.size();
        sort(stones.begin(),stones.end());
        for(int i=len-1;i>0;i--)
        {
            if(stones[i]==stones[i-1])
            {
                stones.pop_back();
                stones.pop_back();
                i--;
            }
            else
            {
                stones[i-1]=stones[i]-stones[i-1];
                stones.pop_back();
            }
            sort(stones.begin(),stones.end());

        }
        if(stones.size()==0)
        {
            return 0;
        }
        else
        {
            return stones[0];
        }
        
    }
};
```
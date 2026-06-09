### [5343. 多次求和构造目标数组](https://leetcode-cn.com/problems/construct-target-array-with-multiple-sums/submissions/)

### 题解
  + 反向模拟，每次找到数列中的最大值进行逆推
  + 利用堆优化查找最大值
  + 注意求和会溢出int型
  + 更多题解: [>>请点击<<](https://tawn0000.github.io/2020/02/08/leetcode-week-contest/)
### 代码
```cpp
class Solution {
public:
    bool isPossible(vector<int>& target) {
        long long int sum = 0;
        priority_queue<int> q;
        for(int i = 0; i < target.size(); i++)
        {
            sum += target[i];
            q.push(target[i]);
        }
        
        while(!q.empty())
        {
            int t = q.top();
            if(t == 1) return true;
            q.pop();
            long long int p = sum - t;
            sum = t;
            if(t - p < 1) return false;
            if(t-p != 1) q.push(t-p); 
        }
        return true;
    }
};
```

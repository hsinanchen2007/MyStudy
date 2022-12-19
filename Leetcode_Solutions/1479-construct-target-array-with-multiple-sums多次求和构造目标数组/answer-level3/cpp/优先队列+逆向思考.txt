### 解题思路
- 和会越加越大，要先往最小的上面加（动态的过程）
- 逆向思考，给定的数组，数字全部push进优先队列
- 数组和往下减去最大的，应该等于1，若小于1，false
- 大于1，先pop原数，再push大于1的那个数进队列

### 代码

```cpp
class Solution {
public:
    bool isPossible(vector<int>& target) {
        long sum = 0, s, i, num;
        priority_queue<long> q;//默认大顶堆
        for(i = 0; i < target.size(); ++i)
        {
        	sum += target[i];//总和
        	q.push(target[i]);
        }
        while(!q.empty() && q.top() != 1)
        {
        	s = sum-q.top();//剩余的和
        	num = q.top()-s;//栈顶-s，应该为1或者比1大的数
        	if(num < 1)//小于1则false
        		return false;
        	q.pop();//弹出栈顶
            if(num != 1)//等于1就不用再放进去了，节省时间
        	    q.push(num);
        	sum -= s;//和减少了s
        }
        return true;
    }
};
```
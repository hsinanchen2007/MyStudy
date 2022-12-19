### 分享一个比较挫的题解，时间28    空间5 可以说很差了，求大佬指导这题用单调栈如何进行优化呢？

下面解题思路
模拟一下买卖股票的过程


	case1：
        7  1  
		7  5  pop 1 push 5    +4
		7 5 3  push 3
		7 5 6  pop 3 push 6   +3
								sum = 7
		7 5 6 4  finish
	
		
    case2：
		1 2  pop 1 push 2   +1
		2 3  pop 2 push 3    +1
		3 4  pop 3 push 4    +1
		4 5  pop 4 push 5    +1
							sum = 4
							
	case3：						
		7  6 4 3 1  return 0
		
	因此：规则就是维护单调递减栈，当破坏规则时候，从栈顶pop算差值然后push新的值


### 代码

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        stack<int> st;
        int profit = 0;
        for(auto day : prices) {
            if(st.empty() || day<st.top()) st.push(day);
            while(!st.empty() && day > st.top()) {
                profit += day - st.top();
                st.pop();
                st.push(day);
            }
        }
        return profit;
    }
};
```
### 解题思路
//思路：维护一个递减的单调栈 ，栈中存储数组元素的对应下标 ，因为答案要求算下标差值 
//假设条件：设当前元素是下标是now，栈顶元素下标是top ，答案是数组res，res【i】代表数组中第i个元素的右边第一个大于它的元素下的标与i的差值 

//关键判断：
//如果now>top,   res【top】 = now - top，  top出栈  
//然后now进栈 

时间复杂度：栈中元素都只进栈出栈各一次，时间复杂度是O(n)
### 代码


```cpp
class Solution {
public:
   vector<int> dailyTemperatures(vector<int>& T) {
    vector<int> res(T.size());
    stack<int> decrease;
    for(int i = 0; i < T.size(); ++i) {
    	if(decrease.empty()) {
    		decrease.push(i);
		}
		else {
	        //在操作stack前判断是否为空 
			while(!decrease.empty() && T[i] > T[decrease.top()]) {
			    res[decrease.top()] = i - decrease.top();
			    decrease.pop();
			}
			decrease.push(i);
		}
	}
	return res;
} 
};
```
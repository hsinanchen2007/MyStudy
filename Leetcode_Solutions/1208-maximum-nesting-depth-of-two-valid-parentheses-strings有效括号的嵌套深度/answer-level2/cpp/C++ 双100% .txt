### 解题思路
其实就不要连续两个括号分到一组就好。
用栈
1. 如果是 `(`，先入栈，判断栈元素数是否是$2$的倍数，是的话 `ans.push_back(1)`，否则就`push_back(0)`；
2. 如果是`)`，先判断栈元素数，再出栈！
怎么想到的呢？自己写个例子，`(((())))`，发现根据不让连续两个括号在一起的原则，第$2$,$4$个`(`应分到`1`组，对应的 `)`也应标成`1`，就发现了出栈前栈元素数分别为`4`,`2`。
### 代码

```cpp
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> ans;
        stack<char> st;
        for (int i=0; i<seq.size(); ++i) {
        	if (seq[i] == '(') { // 如果是(
        		st.push(seq[i]);
        		if (st.size() % 2 == 0)
        			ans.push_back(1);
        		else
        			ans.push_back(0);
			}
        		
        	else { // 如果是 )
        		if (st.size() % 2 == 0)
        			ans.push_back(1);
        		else
        			ans.push_back(0);
        		st.pop();
			}		
		}
        return ans;
    }
};

```
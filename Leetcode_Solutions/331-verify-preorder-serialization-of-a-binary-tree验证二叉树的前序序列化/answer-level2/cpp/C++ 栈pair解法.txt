### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
	bool isValidSerialization(string preorder) {
		stack<pair<string, int>> st;
        stringstream ss(preorder);
        string c;
        while(getline(ss, c, ',')) {
			if (c != "#") st.push(make_pair(c, 0));
			else {
				while (!st.empty() && ++st.top().second == 2)
				{
					st.pop();
				}
				if (st.empty() && getline(ss, c, ',')) return false;
			}
		}
		return st.empty();
	}
};
```
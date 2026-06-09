### 解题思路
此处撰写解题思路
枯燥
### 代码

```cpp
class Solution {
public:
    string reverseLeftWords(string s, int n) {
	
	return (s.substr(n, s.size()-1) + s.substr(0, n));
}
};
```


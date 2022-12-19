### 代码

```cpp
class Solution {
public:
    string reverseStr(string s, int k) {
		for(int i=0;i<s.size();i+=2*k){
			if(s.size()-i>=k)reverse(s.begin()+i,s.begin()+i+k);
			else reverse(s.begin()+i,s.end());
		} 
		return s;
    }
};
```
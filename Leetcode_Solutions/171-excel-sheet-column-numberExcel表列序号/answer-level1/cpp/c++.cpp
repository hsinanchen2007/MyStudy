### 代码

```cpp
class Solution {
public:
    int titleToNumber(string s) {
int sum=0;
		for(int i=0;i<s.size();++i){
			sum*=26;
			sum+=(s[i]-'A'+1);
		}
		return sum;
    }
};
```
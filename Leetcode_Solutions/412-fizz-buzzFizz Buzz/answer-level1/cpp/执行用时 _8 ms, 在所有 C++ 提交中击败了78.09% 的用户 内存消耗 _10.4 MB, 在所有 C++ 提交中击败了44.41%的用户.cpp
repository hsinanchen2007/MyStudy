### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<string> fizzBuzz(int n) {
    	vector<string> s;
    	for(int i=1;i<=n;++i){
    		if(!(i%3) && !(i%5)) s.push_back("FizzBuzz");
    		else if(!(i%3)) s.push_back("Fizz");
    		else if(!(i%5)) s.push_back("Buzz");
    		else s.push_back(to_string(i));
    	}
    	return s;
    }
};
```
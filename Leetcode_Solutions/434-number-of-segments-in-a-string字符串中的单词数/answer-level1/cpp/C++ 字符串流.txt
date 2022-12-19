```
class Solution {
public:
    int countSegments(string s) {
		
		istringstream is(s);
		string word;
		
		int ret = 0;
		
		while(is >> word)
		{
			ret++;
		}
		
		return ret;
    }
};
```

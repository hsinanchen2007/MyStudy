![image.png](https://pic.leetcode-cn.com/20ee6a4fa98db5b85ba7246d74c820b86bedf786d647bef1e582ec21381c1cfa-image.png)

```
class Solution {
public:
    int distinctEchoSubstrings(string text) {
        int i, len, n = text.size(), count = 0;
        string_view t(text);
        for(len = 1; len <= n/2+1; len++)
        {
            set<string_view> set;
        	for(i = 0; i <= n-2*len; ++i)
        	{
        		if(t.substr(i,len) == t.substr(i+len,len))
        			set.insert(t.substr(i,len));
        	}
            count += set.size();
        }
        return count;
    }
};
```

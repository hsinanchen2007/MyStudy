将A重复两遍就会包含所有B的形式，然后判断即可。

```
class Solution {
public:
    bool rotateString(string A, string B) {
        if (A.size() != B.size()) return false;
	    A = A + A;
	    auto idx = A.find(B);
	    if (idx == string::npos)
		    return false;
	    else return true;
    }
};
```

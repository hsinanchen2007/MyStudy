![6.PNG](https://pic.leetcode-cn.com/3bfe96b9dc037240273763ecf204c25f8f9321b2a2a7c00f7b0165fdc13007ce-6.PNG)

```
class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        int i;
		for(i=0;i<A.size()-1;i++)//是否为单调递增 
			if(A[i]>A[i+1])
				break;
		if(i==A.size()-1)
			return 1;
		for(i=0;i<A.size()-1;i++)//是否为单调递减 
			if(A[i]<A[i+1])
				return 0;
		return 1;
    }
};
```

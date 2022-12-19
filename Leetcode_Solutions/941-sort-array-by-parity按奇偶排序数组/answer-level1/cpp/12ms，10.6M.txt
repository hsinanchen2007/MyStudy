### 解题思路
从头开始遍历，找到第一个奇数，再从这个奇数下一个数开始至结尾，找一个偶数，把这两个数替换，就可以了。

### 代码

```cpp
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
	       int len = A.size();
	       int i = 0, j = 0;;
	       while (i < len && j < len) {
	        	if (A[i] % 2 == 0) {
	    		    ++i;
	    	}
    		else {   //找到第一个非偶数
	    		j = i + 1;
	    		while (j < len) {
	    			if (A[j] % 2 == 0) {
                        int temp = A[i];
	    				A[i] = A[j];
	    				A[j] = temp;
	    				++j;   
                        ++i;   
	 			}
				    else {
				    	++j;
			    	}
		    	}  
		     }
	     }
        return A;
     }
};
```
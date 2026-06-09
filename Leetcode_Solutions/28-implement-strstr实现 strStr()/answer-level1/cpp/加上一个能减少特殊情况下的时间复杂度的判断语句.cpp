### 解题思路
考虑到当needle特别长的情况，当haystack运行到倒数needle.size()-1个字符，还没和needle对应上，可以直接返回-1.

### 代码

```cpp
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty())		return 0;
		int m = haystack.size(), n = needle.size(), i = 0, j = 0;
		if (n > m) return -1;
		
		for (i = 0; i < m; i++){  //循环一次取第一个字符串里的字符
			if (j == n) return i - n;
            if (i > (m - n + 1) && j == 0) return -1;	//为了减少特殊情况下的计算量
			if (haystack[i] == needle[j])	++j;
			else {
				i -= j;
				j = 0;
			}
		}
        if (j == n) return i - n;//必须有，如当i=m-1最后一次循环时时，才有++j=n
		return -1;
    }
};
```
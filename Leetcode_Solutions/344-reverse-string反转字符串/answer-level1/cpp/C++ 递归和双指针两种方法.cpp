### 解题思路
1、递归
2、双指针

### 代码


#### 递归

```cpp
class Solution {
public:
	void reverseString(vector<char>& s) {
		if (s.size() == 0) return;
		char *begin, *end;
		begin =&s[0];
		end = &s[s.size()-1];
		reverseS(begin, end);
	}
	void reverseS(char* begin, char* end) {
		if (begin >= end) return;
		else
		{
			char temp = *begin;
			*begin = *end;
			*end = temp;
			reverseS(++begin, --end);
		}
	}
};
```



#### 双指针

```cpp
class Solution {
public:
	void reverseString(vector<char>& s) {
        if(s.size()==0) return;
		char* begin, * end;
		begin = &s[0];
		end = &s[s.size() - 1];
        //交换
		while (begin<end)
		{
			char temp = *begin;
			*(begin++) = *end;
			*(end--) = temp;
		}
	}
};
```
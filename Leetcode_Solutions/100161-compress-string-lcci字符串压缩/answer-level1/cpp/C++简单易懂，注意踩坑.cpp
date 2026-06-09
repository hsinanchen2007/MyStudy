### 解题思路
执行用时 :12 ms, 在所有 C++ 提交中击败了86.18%的用户
内存消耗 :8.6 MB, 在所有 C++ 提交中击败了100.00%的用户
刷题小白的第一道题解，纯粹是记录一下踩的坑，这里需要注意以下两种方式的区别：
```
result += to_string(count);
result = result + to_string(count);
```
operator+=返回的是引用，operator+返回的是值，在string很大的情况下，拷贝行为过多
就会导致超出内存限制。

### 代码
```cpp
class Solution {
public:
    string compressString(string S) {
        char temp = S[0];
    	int count = 1;
	    string result;
	    result.push_back(temp);
	    for (size_t i = 1; i < S.size(); ++i){
		    if (S[i] == temp){
		        count++;
			if (i == S.size() - 1)
				result += to_string(count);
		    }
		    else{
			    result += to_string(count);
			    temp = S[i];
			    result.push_back(temp);
			    count = 1;
			    if (i == S.size() - 1)
				    //result.push_back(to_string(count).c_str);
				    result += to_string(count);
		    }	
    	}
	    int length = result.size();
	    if (length < S.size())
		    return result;
	    else
	    	return S;

    }
};
```
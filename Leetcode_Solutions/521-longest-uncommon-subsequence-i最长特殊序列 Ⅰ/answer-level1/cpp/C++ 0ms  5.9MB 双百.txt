### 解题思路
个人觉得思考清楚后，这道题真的简单到让我怀疑人生，虽然乍看觉得可能会有诈。
思路不解释，直接上代码。

### 代码

```cpp
class Solution {
public:
    int findLUSlength(string a, string b) {
    	int lena = a.length(),lenb = b.length();
    	if(lena != lenb) return max(lena,lenb);
    	if(strcmp(a.c_str(),b.c_str())==0) return -1;
		return lena; 
    }
};
```
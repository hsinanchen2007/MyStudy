### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string defangIPaddr(string address) {
	    string str;
	    for(char c:address){
	    	if(c=='.'){
	    		str+="[.]";
			}else{
				str+=c;
			}
		}
	    return str;
    }
};
```
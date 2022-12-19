### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()){
		return "" ;
	}
	string comstr;
	comstr=strs.at(0);
	string tempstr;
for(auto str:strs){
	for(int i=0;i<str.length();i++){
		if(comstr[i]==str[i]){
			tempstr+=comstr[i];
		}
		else{
			break;
		}
	}
	comstr=tempstr;
	tempstr.clear();
}
if(comstr.empty()){
	return  "" ;
}
return comstr;
    }
};
```
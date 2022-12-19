### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        int size = digits.size();
	    if (0==size)
		    return {};
        vector<string> result;
	    map<char, string> m = {{'2',"abc"},{'3',"def"},
        {'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},
        {'8',"tuv"},{'9',"wxyz"}};
	    for (int i = 0; i < size; i++){//i:取数
		    vector<string> temp;
            if(i==0){
                for(int j=0;j<m[digits[0]].size();j++)
                    result.push_back(string(&m[digits[0]][j]));
                continue;
            }
		    for (int j = 0; j <result.size(); j++){//当前个result里的个数
			    for (int k = 0; k < m[digits[i]].size(); k++){//当前取的数字对应字母数
				    temp.push_back(result[j] + m[digits[i]][k]);
			    }
		    }
		    result = temp;
	    }
	    return result;
    }
};
```
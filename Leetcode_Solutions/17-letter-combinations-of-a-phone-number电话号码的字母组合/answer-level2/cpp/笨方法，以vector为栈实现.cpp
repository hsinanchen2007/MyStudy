### 解题思路
此处撰写解题思路
执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗 :6.8 MB, 在所有 C++ 提交中击败了
100.00%的用户

### 代码

```cpp
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> vct;
        vector<string> res;
        if(0 == digits.length()){
            return vct;
        }
        while(0 != vct.size()|| 0 == res.size()){
            string str = "";
            if(0 != vct.size()){
                str = vct.back();
                vct.pop_back();
            }
            if(str.length() == digits.length()){
                res.push_back(str);
            }
            char c = digits[str.length()];
            switch(c){
            
                case '2':
                    vct.push_back(str+"a");
                    vct.push_back(str+"b");
                    vct.push_back(str+"c");
                    break;
                case '3':
                    vct.push_back(str+"d");
                    vct.push_back(str+"e");
                    vct.push_back(str+"f");
                    break;
                case '4':
                    vct.push_back(str+"g");
                    vct.push_back(str+"h");
                    vct.push_back(str+"i");
                    break;
                case '5':
                    vct.push_back(str+"j");
                    vct.push_back(str+"k");
                    vct.push_back(str+"l");
                    break;
                case '6':
                    vct.push_back(str+"m");
                    vct.push_back(str+"n");
                    vct.push_back(str+"o");
                    break;
                case '7':
                    vct.push_back(str+"p");
                    vct.push_back(str+"q");
                    vct.push_back(str+"r");
                    vct.push_back(str+"s");
                    break;
                case '8':
                    vct.push_back(str+"t");
                    vct.push_back(str+"u");
                    vct.push_back(str+"v");
                    break;
                case '9':
                    vct.push_back(str+"w");
                    vct.push_back(str+"x");
                    vct.push_back(str+"y");
                    vct.push_back(str+"z");
                    break;




            }
        }
        return res;
    }
};
```
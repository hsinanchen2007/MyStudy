### 解题思路
思路不是很好，但是写的比较简单
拆分，翻转，合并

### 代码

```cpp
class Solution {
public:
    void reverseWords(vector<char>& s) {

        if(s.empty()){
            return;
        }

        stringstream sstream;
        for(auto c:s){
            sstream << c;
        }

        string str;
        vector<string> strvec;

        while(getline(sstream,str,' ')){
            strvec.push_back(str);
            strvec.push_back(" ");
        }

        strvec.pop_back();

        reverse(strvec.begin(), strvec.end());

        vector<char> charvec;

        for(auto tmpstr:strvec){
            for(auto c:tmpstr){
                charvec.push_back(c);
            }
        }

        s = charvec;

        return;
    }
};
```
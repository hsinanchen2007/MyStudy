### 解题思路
我就无脑用了一下istringstream的操作，先把原字符串存进流里面，然后再从流里面用'>>'读入（自动忽略空白字符），最后倒着输出就行了

### 代码

```cpp
class Solution {
public:
    string reverseWords(string s) {
        vector<string> vec;
        istringstream sss(s);
        string temp;
        while(sss>>temp){
            vec.push_back(temp);
        }
        string ans="";
        for(int i=vec.size()-1;i>=0;i--){
            ans+=vec[i];
            if(i!=0) ans+=" ";
        }
        return ans;
    }
};
```
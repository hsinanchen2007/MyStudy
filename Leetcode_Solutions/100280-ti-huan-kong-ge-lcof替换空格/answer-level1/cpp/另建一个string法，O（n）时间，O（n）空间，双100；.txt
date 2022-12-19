### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string replaceSpace(string s) {
if(s.empty())return s;  //空字符串的情况
string temp;   //新建一个string
for(auto v:s)
{
    if(v!=' ')
    temp.push_back(v);
    else{
    temp.push_back('%');temp.push_back('2');temp.push_back('0');}
}
return temp; 
    }
};
```
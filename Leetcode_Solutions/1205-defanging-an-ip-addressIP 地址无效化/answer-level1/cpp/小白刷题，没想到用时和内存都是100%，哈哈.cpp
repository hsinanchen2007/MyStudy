### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string defangIPaddr(string address) {
        string s1="[.]";
        for(int i=address.size();i>=0;i--){
            if(address[i]=='.'){
        address.replace(i,1,s1);
            }
        }
        return address;
    }
};
```
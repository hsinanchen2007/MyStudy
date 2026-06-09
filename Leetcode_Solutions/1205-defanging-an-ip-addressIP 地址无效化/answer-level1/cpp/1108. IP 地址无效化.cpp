### 解题思路
遍历+条件判断

### 代码

```cpp
class Solution {
public:
    string defangIPaddr(string address) {
        string res="";
        string  t="[.]";
        for(int i=0;i<address.size();i++){
            if(address[i]=='.') {
                res+=t;
            }
            else res+=address[i];
        }
        return res;
    }
};
```
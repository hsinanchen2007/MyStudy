### 解题思路

### 代码

```cpp
class Solution {
public:
    string defangIPaddr(string address) {
        for(int i=0;i<address.length();){
            if(address[i]=='.'){
                address.replace(i,1,"[.]");
                i+=3;
            }
            else{
                i++;
            }
        }
        return address;
    }
};
```
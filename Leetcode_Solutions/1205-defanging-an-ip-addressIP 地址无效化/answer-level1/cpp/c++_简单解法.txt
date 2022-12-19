![image.png](https://pic.leetcode-cn.com/40e1a5ef6075e092fe61b61615bdc4d5b09bb5232f68aef23b793342b976b9fe-image.png)

```cpp
class Solution {
public:
    string defangIPaddr(string address) {
        string s;
        for (int i = 0; i < address.size(); i++){
            if (address[i] == '.'){
                s.append("[.]");
                continue;
            }
            s += address[i];    
        }
        return s;
    }
};
```
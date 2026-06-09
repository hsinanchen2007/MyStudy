
## 思路：

一次遍历，正向遍历


![image.png](https://pic.leetcode-cn.com/c04b8b1b2f6719f9d05b51934326538afda5c9733dfce83ad8d518548a96a275-image.png)




## 

```c++
class Solution {
public:
    string defangIPaddr(string address) {
        string ret = address;
        for(int i=0;i<ret.size()-1;i++){
            if(isdigit(ret[i]) && ret[i+1] == '.'){
                ret.erase(ret.begin() + i+1);
                ret.insert(i+1, "[.]");
                cout<<ret<<endl;
            }
        }
        return ret;
    }
};
```
```
class Solution {
public:
    bool checkRecord(string s) {
        int n1 = 0;
        int n2 = 0;
        for(auto c : s)
        {
            if(c == 'A'){
                n1++;
                n2 = 0; //这个地方也要清空
            }
            else if(c == 'L')
                n2++;
            else
                n2 = 0;
            if(n1 > 1 || n2 > 2)
                return false;
        }
        return true;

    }
};
```
![image.png](https://pic.leetcode-cn.com/e65f35c048657889c5a106d87a53a077be21033da1437cb49c604860ce5f9279-image.png)

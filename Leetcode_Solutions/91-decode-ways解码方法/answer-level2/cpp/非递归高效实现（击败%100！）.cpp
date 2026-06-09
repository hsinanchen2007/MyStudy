![image.png](https://pic.leetcode-cn.com/43d4a0c03be9992d705885de0d41627703fad1518653333beb64a0f9087fdfc1-image.png)
```
class Solution {
public:
    int numDecodings(string s) {
        int front;
        int back;
        int size = s.size();
        int rc;
        
        if (*s.crbegin() == '0')
            back = 0;
        else
            back = 1;

        if (s.size() > 1) {
            rc = 0;
            if (s[size - 2] != '0') {
                rc += back;
                
                if (s[size - 2] == '1' || (s[size - 2] == '2' && s[size - 1] >= '0' && s[size - 1] <= '6')) {
                    rc++;
                }
            }
            front = rc;
        } else {
            return back;
        }

        for (auto i = size - 3; i >= 0; --i) {
            rc = 0;
            if (s[i] != '0') {
                rc += front;
                
                if (s[i] == '1' || (s[i] == '2' && s[i+1] >= '0' && s[i+1] <= '6')) {
                    rc += back;
                }
            }
            //cout << front << " " << back << " " <<  rc << endl;
            back = front;
            front = rc;
        }
        return front;
    }
};
```

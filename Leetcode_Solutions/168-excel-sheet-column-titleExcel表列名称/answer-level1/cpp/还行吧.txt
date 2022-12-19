```
class Solution {
public:
    string convertToTitle(int n) {
        string forend;
        bool flag = false;
        while(n >= 26) {
           int yushu = n % 26;
            if(yushu == 0) {
                n = (n - 26) / 26;
                forend = forend + char(90);
            } else {
                n = (n - yushu) / 26;
                forend = forend +  char(64 + yushu);
            }
            flag = true;
        }
        if(flag == false) {
            forend = forend + char(n + 64);
            return forend;
        } else {
            if(n == 0){
                reverse(forend.begin(),forend.end());
            } else {
                forend = forend + char(n + 64);
                reverse(forend.begin(),forend.end());
            }  
        }
        return forend;
    }
};
```
![QQ图片20191202224208.png](https://pic.leetcode-cn.com/3a1f7ede0bad030091b1250de2cbbcd8cbc9503c502a9bb26c1228fae3257615-QQ%E5%9B%BE%E7%89%8720191202224208.png)


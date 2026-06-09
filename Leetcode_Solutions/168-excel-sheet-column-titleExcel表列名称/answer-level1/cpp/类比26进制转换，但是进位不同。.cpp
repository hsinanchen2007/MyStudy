### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string convertToTitle(int n) {
        string res="";
        --n;
        while(n>=0){
            char h = n%26+'A';
            res.push_back(h);
            n=n/26;
            n--;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
```
![image.png](https://pic.leetcode-cn.com/79f1334d3c44bdb492e7792ba05e08c04025df51984ea7f8f9673e365e9fcb7e-image.png)

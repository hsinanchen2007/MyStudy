### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/2dd3a7390912d4f5c71a1d9f7777da633fcd800561c21f246fbe5ddf5377d557-image.png)

### 代码

```cpp
class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int sizeS = s.size();
        int sizeT = t.size();
        if(sizeS == 0 && sizeT == 0) {
            return false;
        }
        if(s == t) {
            return false;
        }
        if (abs(sizeS - sizeT) > 1) {
            return false;
        }
        if (sizeT > sizeS){
            return oneMoreOrLess(s, t);
        }else if (sizeT < sizeS) {
            return oneMoreOrLess(t, s);
        }else {
            int distinctCount = 0;
            for (int ps = 0, pt =0; pt < sizeT; ps++,pt++) {
                if (s[ps] != t[pt]) {
                    distinctCount++;
                    if(distinctCount>1){
                        return false;
                    }
                }
            }
            return true;
        }
    }
    bool oneMoreOrLess(string shorter, string longer)
    {
        int s = 0;
        int l = 0;
        while (l < longer.size()) {
            if (shorter[s] == longer [l]) {
                ++s; ++l;
            }else{
                ++l;
            }
        }
        return s == (l -1);
        
    }
};
```
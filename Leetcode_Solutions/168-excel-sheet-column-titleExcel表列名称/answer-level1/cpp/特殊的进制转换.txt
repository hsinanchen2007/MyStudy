进制转换，代码仅radix取值不同。但这里的26进制转换略有区别，因为从1开始，每次操作（求模求商）都要减一。
```
class Solution {
public:
    string convertToTitle(int n) {
        string res;
        for(; n; n=(n-1)/26)
            res.push_back('A'+(n-1)%26);
        reverse(res.begin(),res.end());
        return res;
    }
};
```

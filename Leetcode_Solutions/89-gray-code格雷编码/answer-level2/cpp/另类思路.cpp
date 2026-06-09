 格雷码要求相邻的数字只有一位不同，那我们直接让最高位不同就行了。
例如我们只有`0，1`，然后逆序加上最高位`10`并加入栈内就得到`00,01,11,10`，这样就能得到2位的格雷码，更高位的格雷码依次类推。
```
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res = {0};
        int bitCnt = 0;
        int bitMaxNum = 1;
        while (bitCnt < n) {
            for (int i = res.size() - 1; i >= 0; i--) res.push_back(res[i] + bitMaxNum);
            bitMaxNum = bitMaxNum << 1;
            bitCnt++;
        }
        return res;
    }
};
```

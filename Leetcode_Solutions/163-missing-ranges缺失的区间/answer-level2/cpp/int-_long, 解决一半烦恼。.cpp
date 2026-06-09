### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/abdc8299c98b63b5a83375486361939ab88d65b0056a22475c3932896c642973-image.png)

### 代码

```cpp
class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> res = {};
        vector<long> numLong;
        for (int k : nums) {
            numLong.push_back((long)k);
        }
        if (numLong.empty()) {
            string x = lower==upper? to_string(lower):(to_string(lower)+"->"+to_string(upper));
            res.push_back(x);
            return res;
        }
        int startPtr = 0;
        if (lower > numLong[0]){
            startPtr = lower_bound(numLong.begin(), numLong.end(), lower) - numLong.begin();
            if (lower > numLong[startPtr] && (numLong[startPtr+1] - lower > 1)) {
                res.push_back(to_string(lower)+"->"+to_string(numLong[startPtr]));
            }
            while ( numLong[startPtr+1] - numLong[startPtr] == 1){
                startPtr++;
            }
        }else if(lower < numLong[0]) {
            if(numLong[0] - lower > 1) {
                res.push_back(to_string(lower)+"->"+to_string(numLong[0]-1));
            }else{
                res.push_back(to_string(lower));
            }
        }
        int endPtr = numLong.size()-1;
        if (upper < numLong[endPtr]) {
            endPtr = upper_bound(numLong.begin(), numLong.end(), upper) - numLong.begin() -1;
        }
        while (startPtr < endPtr) {
            int num1 = numLong[startPtr];
            startPtr++;
            if (numLong[startPtr] - 2 > num1){
                res.push_back(to_string(num1+1)+"->"+to_string(numLong[startPtr]-1));
            }
            if (numLong[startPtr] - 2 == num1){
                res.push_back(to_string(num1+1));
            }
        }
        if((upper != numLong[endPtr]) && (upper - 1 != numLong[endPtr])) {
            res.push_back(to_string(numLong[endPtr]+1)+"->"+to_string(upper));
        }else if(upper - 1 ==  numLong[endPtr]) {
            res.push_back(to_string(upper));
        }
        return res;
    }
};
```
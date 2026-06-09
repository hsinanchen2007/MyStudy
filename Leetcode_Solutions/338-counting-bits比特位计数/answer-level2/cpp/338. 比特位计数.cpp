查表法，时间复杂度$O(8N)$。

```c++ []
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ans(num+1,0);
        for(int i = 1;i <= num;i++){
            ans[i] = getBits(i);
        }
        return ans;
    }
private:
    int bits[16] = {
        0,1,1,2,1,2,2,3,
        1,2,2,3,2,3,3,4
    };
    int getBits(int num){
        int bit = 0;
        while(num){
            bit += bits[num & 0xf];
            num >>= 4;
        }
        return bit;
    }
};
```
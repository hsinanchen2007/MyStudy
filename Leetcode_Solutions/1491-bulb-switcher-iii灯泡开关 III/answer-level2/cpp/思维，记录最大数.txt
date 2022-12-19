当前i个数最大值与i相等时，证明1-i的灯都亮了,i灯变蓝。
所以只要遍历一遍并记录到每个位置的最大值与i值相比，相等则次灯变蓝，结果+1。
```
class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
        int mx=0;
        int ans=0;
        for(int i=0;i<light.size();i++){
            mx=max(mx,light[i]);
            if(i+1==mx) ans++;
        }
        return ans;
    }
};
```

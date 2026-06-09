按照每个数对的后面一个数从小到大排序，时间O(nlog(n))，从第一个数对开始，依次判断后面的数对，能否与前面的数对组成数对链，能组的话长度就+1，这样找到的数对链就是最优解
```
class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b) {return a[1]<b[1];}
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), cmp);
        int len=pairs.size();
        if(len==0)
            return 0;
        int end=pairs[0][1],ans=1;
        for(int i=1;i<len;i++){
            if(pairs[i][0]>end){
                end=pairs[i][1];
                ans++;
            }
        }
        return ans;
    }
};
```

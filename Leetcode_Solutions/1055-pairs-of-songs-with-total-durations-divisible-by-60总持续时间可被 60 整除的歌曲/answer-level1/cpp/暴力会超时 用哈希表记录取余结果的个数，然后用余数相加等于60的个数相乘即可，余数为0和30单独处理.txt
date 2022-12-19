```
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int cnt=0;
        int hashtable[60]={0};
        for(int i=0;i<time.size();++i){
            hashtable[time[i]%60]++; //余数哈希表
        }
        for(int i=1;i<30;++i){
            cnt+=hashtable[i]*hashtable[60-i]; //余数相加等于60的可以组队
        }
        //单独处理余数为0和30的情况
        if(hashtable[0]>=2) cnt+=(hashtable[0]-1)*hashtable[0]/2;
        if(hashtable[30]>=2) cnt+=(hashtable[30]-1)*hashtable[30]/2;
        return cnt;
    }
};
```
执行用时 :28 ms, 在所有 C++ 提交中击败了93.44%的用户
内存消耗 :23.4 MB, 在所有 C++ 提交中击败了5.03%的用户

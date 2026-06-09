将5个元音字母出现次数的奇偶视为一种状态，一共有32种状态，不妨使用一个整数代表状态，第0位为1表示a出现奇数次，第一位为1表示e出现奇数次……以此类推。仅有状态0符合题意。

而如果子串[0，i]与字串[0,j]状态相同，那么字串[i+1,j]的状态一定是0，因此可以记录每个状态第一次出现的位置，此后再出现该状态时相减即可。
需要注意状态0首次出现的位置应该设定为-1。

在计算状态的时候可以利用异或运算。

```
class Solution {
public:
    int findTheLongestSubstring(string s) {
        vector<int> pre(32,INT_MAX);
        pre[0]=-1;
        const int N=s.size();
        int cur=0;
        int ans=0;
        for(int i=0;i<N;++i){
            switch(s[i]){
                case 'a':cur^=1;break;
                case 'e':cur^=2;break;
                case 'i':cur^=4;break;
                case 'o':cur^=8;break;
                case 'u':cur^=16;break;
                default:break;
            }
            if(pre[cur]==INT_MAX) pre[cur]=i;
            else ans=max(ans,i-pre[cur]);
        }
        return ans;
    }
};
```

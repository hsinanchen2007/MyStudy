前面的各位大佬已经写了很详细的题解，但第一次见这种字符串+组合计数类型的同学们可能很难一下子反应过来这题和KMP、DP到底有啥关系，以及这个思路是怎么想到的。所以这里给大家解释一下。

这道题的最大难点在于，我们要求计算有多少个字符串“不包含”某个子串。而这个子串本身是可以重复的，这就导致重复计数的问题。也就是说，假如我们的思路是计算所有 sa 到 sb 的字符串有多少个，再减去所有不符合条件的字符串，那么减的过程中就得考虑“包含好几个evil串”的这个情况。

比如说，不包含的子串为 "abaab"，那么 "abaabaab" 这个字符串中包含两个 "abaab"，被“减”了两次，根据容斥原理，就需要返还一次。那么怎么判断字符串中有没有/有几个 evil 串呢？这就是 KMP 算法的范畴了。

因此需要用到KMP。

KMP算法应该都不陌生。该算法根据匹配串构建了一个状态机，也就是实现中的“Fail数组”。不理解KMP和状态机有啥区别的同学可以看看这个博客：[从有限状态机理解KMP](https://www.cnblogs.com/courtier/p/4273193.html)。

但传统的字符串算法中，我们是对用一个匹配串去匹配一个原字符串，现在我们没有“一个”源字符串，而是有很多很多的字符串。假如一个一个枚举，这个复杂度肯定难以想象了。

因此要用到DP。

具体来说，这题就是想象把字典序从 sa 到 sb 之间的所有字符串全都写出来，然后一起放进KMP的状态机中跑。在其过程中，所有达到了最后一个节点（也就是KMP中匹配成功的那个节点）的字符串就是不符合条件的，而其他字符串都是符合条件的。

由于我们最后只需要求出数量，因此我们只需用一个数据结构来保存“每个状态的节点分别有多少个”，然后用动态规划的方法进行转移即可。

具体的状态转移设计和代码实现可以参见其他dalao的题解，就不再赘述了。

# 代码
写的比较挫，慎读。
```
const int mod = 1000000007;
class Solution {
public:
    int findGoodStrings(int n, string a, string b, string e) {
        int en = e.length();
        vector<int> fa(en+1, 0);
        int i = 0, j = fa[0] = -1;
        for(; i<en; i++, j++){
            while(j>=0 && e[j]!=e[i])j=fa[j];
            fa[i+1]=j+1;
        }
        int plen = 0;
        for(int i=1; i<=n; i++){
            if(a.substr(0, i) == b.substr(0, i))plen = i;
            else break;
        }
        int now = 0, flag = false;
        for(int i=0; i<plen; i++, now++){
            while(now!=-1 && a[i]!=e[now]){
                now=fa[now];
            }
            if(now==en-1){
                return 0;
            }
        }
        if(plen == n){
            return 1;
        }
        vector<int> sc(en, 0);
        for(int i = a[plen]-'a'+1; i<b[plen]-'a'; i++){
            int noww = now;
            while(noww!=-1 && i+'a'!=e[noww]){
                noww=fa[noww];
            }noww++;
            if(noww<en)sc[noww]++;
        }
        int nowa = now;
        while(nowa!=-1 && a[plen]!=e[nowa]){
            nowa=fa[nowa];
        }nowa++;
        int nowb = now;
        while(nowb!=-1 && b[plen]!=e[nowb]){
            nowb=fa[nowb];
        }nowb++;
        for(int p=plen+1; p<n; p++){
            vector<int> d(en, 0);
            if(nowa<en)
                for(int i=a[p]-'a'+1; i<26; i++){
                    int noww = nowa;
                    while(noww!=-1 && i+'a'!=e[noww]){
                        noww=fa[noww];
                    }noww++;
                    if(noww<en)d[noww]++;
                }
            if(nowb<en)
                for(int i=0; i<b[p]-'a'; i++){
                    int noww = nowb;
                    while(noww!=-1 && i+'a'!=e[noww]){
                        noww=fa[noww];
                    }noww++;
                    if(noww<en)d[noww]++;
                }
            for(int c=0; c<26; c++){
                for(int nn=0; nn<en; nn++){
                    int now = nn;
                    while(now!=-1 && c+'a'!=e[now]){
                        now=fa[now];
                    }now++;
                    if(now<en)(d[now]+=sc[nn])%=mod;
                }
            }
            sc=d;
            if(nowa<en){
                while(nowa!=-1 && a[p]!=e[nowa]){
                    nowa=fa[nowa];
                }nowa++;
            }
            if(nowb<en){
                while(nowb!=-1 && b[p]!=e[nowb]){
                    nowb=fa[nowb];
                }nowb++;
            }
        }
        int ans = 0;
        for(int j=0; j<en; j++){
            ans=(ans+sc[j])%mod;
        }
        ans+=(nowa<en)+(nowb<en);
        return ans;
    }
};
```
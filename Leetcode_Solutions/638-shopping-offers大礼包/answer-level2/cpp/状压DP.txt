**主要能状压的原因是他的状态只有$7*7$个，直观地就能想到小于等于6维的DP，不过由于这个维会变，难道你会每个维度都特判？显然代码量感人。**

**这种问题有一个解决办法就是状压到一个7进制数中，然后就可以愉快地DP啦。不过效率感人qwq，大致算了个极端复杂度$O(6+106*7^7*(6*2))$。**

**状态DP其实也是一种暴力，效率啥的就别纠结啦，动态规划还是应该学习它的思想！**

```cpp
class Solution {
    const int Decinal[7] = {1,7,49,343,2401,16807,117649};
public:

    //把第x种物品有y个的数压入7进制数中，传该7进制的10进制表示数
    inline int change1(int x, int y) {
        return y * Decinal[x - 1];
    }

    //把集合S的k倍压入7进制数中，传该7进制的10进制表示数
    inline int change2(vector<int>& S, int n) {
        int res = 0;
        for(int i=0; i<n; i++) res += (S[i] * Decinal[i]);
        return res;
    }

    //检查是否可以再卖一个礼包S
    inline bool check(vector<int>& S, vector<int>& needs, int n, int pack) {
        for(int i=0; i<n; i++) {
            if( (pack % 7) + S[i] > needs[i]) 
                return false;
            pack /= 7;
        }
        return true;
    }

    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        //"只允许尽可能地不贵，不允许浪费" -- 就是购物清单的背包恰好装满的最少费用
        
        //把单件物品也封装成一个礼包方便后面进行完全背包
        for(int i=0; i<price.size(); i++) {
            vector<int> tmp(price.size()+1, 0);
            tmp[price.size()]=price[i];
            tmp[i]=1;
            special.push_back(tmp);
        }

        int box = special.size(); //礼包种类的数量
        int goods = price.size(); //物品种类的数量
        int tot = change2(needs, goods); //规模：最终要达到的状态
        vector<long long> dp(tot+1, INT_MAX); //达到最终规模所需要的最少费用,初始化为INT_MAX，因为要求最小值
        
        dp[0]=0; //0个物品的最小值为0

        for(int i=0; i<box; i++) {
            for(int j=0; j<=tot; j++) {
                if(!check(special[i], needs, goods, j)) continue; //非法卖礼盒
                int state = j + change2(special[i], goods); //卖该物品后的状态
                dp[state] = min(dp[state], dp[j]+special[i][goods]); //状态更新
            }
        }            
        return dp[tot];
    }
};

```
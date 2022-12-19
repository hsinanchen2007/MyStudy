本题目很明显使用动态规划，主要难度在于路径比较。
动态规划方程如下：
dp[i] 为到i节点的最小花费，如果为-1，代表i点不可达。
dppre[i] 代表 i节点优路径时它的上一节点位置，最终如果dp[N-1]为-1代表不可达，返回空路径，否则，例用dppre迭代回归就能得到最优路径。
dp[i]为j~i-1中非0节点中最小的加上A[i],最大的困难在于，它的前面的节点可能很多花费是相等的，我们需要比较出路径字典序最优的。

![题解.jpg](https://pic.leetcode-cn.com/ded0c04bc2694227523d0466b1ccb2eb520836cfab22f898dab791dac822b7b3-%E9%A2%98%E8%A7%A3.jpg)

为了比较a b两点的路径，需要找到叉入口处，从后往前检索，哪条路的节点当前在最后面，哪条路先走，哪条路径先到汇合点，另一条路就是最优的。详细请看代码：


```
class Solution {
public:
    bool cmp(int j,int mIndex,vector<int>& dpPre){
        while(j>mIndex) j=dpPre[j];
        if(j==mIndex) return true;
        return !cmp(mIndex,j,dpPre);
    }
    vector<int> cheapestJump(vector<int>& A, int B) {
        //cout<<A[11]+A[46]<<" "<<A[37]<<endl;
        vector<int> vAns;
        int N=A.size();
        if(N==0)
            return vAns;
        if(N==1){
            vAns.push_back(1);
            return vAns;
        }
        vector<int> dp(N,-1);  ///记录到i点最小花费
        vector<int> dpPre(N);   //记录到i点最小花费的前一节点
        dp[0]=A[0];
        for(int i=1;i<N;i++){
            if(A[i]==-1)
                continue;
            int b=max(0,i-B);  ///可以跳到i节点的起始处
            int mFei=INT_MAX;
            int mIndex=-1;
            for(int j=b;j<i;j++){
                if(dp[j]!=-1){
                    if(dp[j]<mFei){
                        mFei=dp[j];
                        mIndex=j;                        
                    }else if(dp[j]==mFei){     //要判断j的前面有没有mIndex

                        if(cmp(j,mIndex,dpPre)){
                            mIndex=j;                              
                        }
                    }

                }
            }
            if(mFei!=INT_MAX){
                dp[i]=A[i]+mFei;
                dpPre[i]=mIndex;
            }
        }
        if(dp[N-1]<0)
             return vAns;
        int last=N-1;
        do{
            vAns.push_back(last+1);
            last=dpPre[last];
        }while(last!=0);
        vAns.push_back(1);
        reverse(vAns.begin(),vAns.end());
        //cout<<dp[4]<<endl;
        return vAns;
    }
};
```



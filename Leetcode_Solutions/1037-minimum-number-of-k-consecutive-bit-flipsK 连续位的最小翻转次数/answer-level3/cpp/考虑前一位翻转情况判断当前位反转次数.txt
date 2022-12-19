思路：
        这道题很明朗是要通过从左到右贪心遍历的实现，因此问题主要集中于如何确定第i点之前的翻转对第i点的影响。因为没看懂官方题解，所以想了一个    稍微复杂的方法。
        记B[j]表示以j为起点是否有过反转，有反转则记为true，反之记为false，那么第i点受到之前点反转的影响 与 第i-1点是否改变大小 之间的差距只     在于以i-K为起点是否有过反转。（就是除了以i-K为起点的反转，剩下i点之前的反转都是同时影响第i-1点和第i点。


    int minKBitFlips(vector<int>& A, int K) {
        
        int ans=0;
        vector<bool>B(A.size(),false);
        for(int i=0;i<A.size()-K+1;i++)
        {
            //默认未被反转
            bool flag=false;
            //前一个被反转
            if(i>=1)
                flag^=(1!=A[i-1]);
            //前一个与当前反转不同的点
            if(i>=K)
                flag^=B[i-K];
            if(A[i]^flag==false)
            {
                B[i]=true;
                ans++;
                cout<<i<<"  ";
            }
        }
        
        for(int i=A.size()-K+1;i<A.size();i++)
        {
            bool flag=false;
            if(i>=1)
                flag^=(1!=A[i-1]);
            if(i>=K)
                flag^=B[i-K];
            
            if(A[i]^flag==false)
                return -1;
        }
        return ans;
    }
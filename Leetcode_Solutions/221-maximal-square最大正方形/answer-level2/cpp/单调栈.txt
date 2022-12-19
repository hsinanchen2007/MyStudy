### 利用单调栈
可以利用84题和85题的思路来做
扫描每一行,构建形如84题的柱状图
现在要求的是正方形的面积,因此加入一个判断.
如果从当前柱子左右延伸的宽度不小于高度,则可以构成正方形.
代码如下
```cpp
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m=matrix.size();
        if(m==0)
            return 0;
        int n=matrix[0].size();
        vector<int> hist(n);
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]=='1')
                    hist[j]+=1;
                else
                    hist[j]=0;
            }
            // for(int i=0;i<hist.size();i++)
            //     cout<<hist[i]<<" ,";
            // cout<<endl;
            ans=max(ans,maxRec(hist));
        }
        return ans;
    }
    int maxRec(vector<int>&hist){
        hist.push_back(0);
        hist.insert(hist.begin(),0);
        int n=hist.size();
        int ans=0;
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty()&&hist[st.top()]>hist[i]){
                int j=st.top();
                st.pop();
                int k=st.top();
                //如果可以构成一个正方形
                if(hist[j]<=(i-k-1)){
                    ans=max(ans,hist[j]*hist[j]);
                }
            }
            st.push(i);
        }
        hist.pop_back();
        hist.erase(hist.begin());
        return ans;
    }
};
```
时间复杂度$O(mn)$,空间复杂度$O(n)$
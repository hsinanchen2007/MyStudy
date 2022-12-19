
自己直接的思路。  排序nlogn ,  运算O(n + n) 吧 rear的大小为最大值最小值的差那么长。 接着就是遍历A
```
class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        if(A.size() == 0) return 0;
        int maxx = A[0], minn = A[0];
        for(auto a:A){
            maxx = max(maxx,a);
            minn = min(minn,a);
        } 
        vector<int>vis (maxx+1,0);
        for(auto a:A) vis[a]++;
        vector<int>rear;
        for(int i=maxx;i>=minn;i--){
            if(!vis[i]){
                rear.push_back(i);
            }
        }
        // 如果可以修改A数组，不能就重新创建
        sort(A.begin(),A.end());
        int ans =0 ;
        int high = -1;
        for(int i=0;i<A.size();i++){
            while(rear.size() && rear[rear.size()-1]<=A[i]) {
                rear.pop_back();// 删除不能用的。
            }
            if(vis[A[i]] > 1){
                vis[A[i]]--;
                if(rear.size()){
                    ans += rear[rear.size()-1] - A[i];
                    rear.pop_back();
                }else{
                    if(high == -1){
                        high = maxx+1;  
                    }
                    ans += high - A[i];
                    high ++;
                }
                
            }
        }
        return ans;
    }
};
```

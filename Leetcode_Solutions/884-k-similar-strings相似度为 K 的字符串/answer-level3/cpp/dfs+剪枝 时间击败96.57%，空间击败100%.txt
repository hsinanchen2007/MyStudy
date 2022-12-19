### 解题思路
dfs+剪枝
可以估计剩余部分需要的最小交换次数，据此进行剪枝

### 代码

```cpp
class Solution {
  int ans=INT_MAX;
public:
    int kSimilarity(string A, string B) {
      int len=A.size();
      dfs(A,B,0,0);
      return ans;
    }
    void dfs(string& a,string& b,int cur,int step){
      if(step>=ans) return;
      if(cur>=a.size()) {ans=min(ans,step);return;}
      if(a[cur]==b[cur]){dfs(a,b,cur+1,step);return;}
      int cnt=0;
      for(int i=cur+1;i<a.size();++i){
        if(a[i]!=b[i]) ++cnt;
      }
      if(step+(cnt+1)/2>=ans) return;
      for(int i=cur+1;i<a.size();++i){
        if(a[i]==b[cur]) {
          swap(a[i],a[cur]);
          dfs(a,b,cur+1,step+1);
          swap(a[i],a[cur]);
        }
      }
    }
};

```
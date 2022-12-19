### 解题思路
此处撰写解题思路
递归
### 代码

```cpp
class Solution {
public:
    int ans=0;
    bool visit[50010];
    bool dfs(vector<int>& arr, int start){
        if(ans>0)
            return true;
        if(start<0||start>=arr.size()){
            return false;
        }
        if(arr[start]==0){
            ans++;
            return true;
        }
        int judge=false,judge1=false;
        if(start+arr[start]>=0&&start+arr[start]<arr.size()&&visit[start]==false){
            visit[start]=true;
            judge=dfs(arr,start+arr[start]);
            visit[start]=false;
        }
        if(start-arr[start]>=0&&start-arr[start]<arr.size()&&visit[start]==false){
            visit[start]=true;
            judge1=dfs(arr,start-arr[start]);
            visit[start]=false;
        }
        return judge||judge1;
    }
    bool canReach(vector<int>& arr, int start) {
         int j=dfs(arr,start);
         return j;
    }
};
```
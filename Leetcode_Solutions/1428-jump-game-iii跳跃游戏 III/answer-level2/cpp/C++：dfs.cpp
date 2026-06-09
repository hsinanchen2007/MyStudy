**题解：**
典型的dfs题，需要理解一下注意点，具体实现直接看代码即可。

**注意：**
1）每个点只需要访问一次，因为如果该点不能跳到0，那么通过其他跳法跳到该点也不能跳到0，所以每访问一个点我们就需要记录一次。
2）若跳到0，我们就不必继续dfs了，直接返回true即可。

**代码如下：**
```cpp
class Solution {
public:  
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        return dfs(arr,start,n);
    }
    
    bool visited[50009];
    bool dfs(vector<int>& arr,int start,int n){
        if(arr[start]==0)return true;
        else{
            visited[start]=1;
            bool flag=false;
            
            if(start+arr[start]>=0&&arr[start]+start<n&&!visited[arr[start]+start]){
                flag|=dfs(arr,arr[start]+start,n);
            }
            if(start-arr[start]>=0&&start-arr[start]<n&&!visited[start-arr[start]]){
                flag|=dfs(arr,start-arr[start],n);
            }
            return flag;
        } 
    }
};
```

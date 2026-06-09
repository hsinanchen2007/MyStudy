
![image.png](https://pic.leetcode-cn.com/41e5f1cd1a3669203cb602b6b74095f1386bf1e4cdc0b4f461cc5e8f02db2818-image.png)

分析如下：
```
/*
1.判断数组中是否有0元素，如果没有，直接返回false(处理特殊情况)
2.使用vis表示可以走到的位置，vis[start]=true;
使用while，每次从所有走过的位置向两边走，如果新的位置没有访问，那么访问这个位置。
3.如果一轮while循环之后没有新的位置被访问到，那么说明不能继续访问新的位置
4.判断是否0所在位置可以被访问到
*/
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int len=arr.size();
        bool have0=false;
        vector<bool>vis;
        for(int i=0;i<len;i++){
            if(arr[i]==0) have0=true;
            vis.push_back(false);
        }

        if(have0==false) return false;

        int change=true;
        vis[start]=true;

        while(change){
            change = false;
            for(int i=0;i<len;i++){
                if(vis[i]==true){
                    int a=i+arr[i],b=i-arr[i];
                    if(a<len && vis[a]==false){
                        vis[a]=true;
                        change=true;
                    }
                    if(b>=0 && vis[b]==false){
                        vis[b]=true;
                        change=true;
                    } 

                }
            }
        }
        for(int i=0;i<len;i++){
            if(arr[i]==0 && vis[i]==true) return true;
        } 
        return false;
    }
};
```

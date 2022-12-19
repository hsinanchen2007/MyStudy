//广度优先搜索
//使用队列保存元素下标
//使用bool类型的数组判断该元素是否进入过队列，不使用会提示超时
```
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        queue<int> que;//地址保存队列
        que.push(start);
        int loc;
        bool visit[n] = {false};//判断该元素是否已经进入过队列
        visit[start] = true;
        while(!que.empty()){
            loc = que.front();
            que.pop();
            if(arr[loc] == 0) return true;
            else{
                if(loc + arr[loc] < arr.size() &&  visit[loc + arr[loc]] == false){//如果地址没越界并且没进入过队列，那么入队
                     que.push(loc+arr[loc]);
                     visit[loc + arr[loc]] = true;
                }
                if(loc - arr[loc] >= 0 &&  visit[loc - arr[loc]] == false){
                     que.push(loc-arr[loc]);
                     visit[loc - arr[loc]] = true;
                }
            }
        }
        return false;
    }
};
```

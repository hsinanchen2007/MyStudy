方法一：
```
//先按照会议的最晚开始时间排序，因为时间为最晚开始的会议当前最为紧急，所以最早开比较好
inline bool cmp(vector<int>&a,vector<int>&b){
    return a[1]<b[1];//按照最晚开始时间排序
}
class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end(),cmp);
        //int ans=0;
        int n=events.size();
        set<int>res;//set具有去重的作用
        for(auto v:events){//v是一个数组[,];
            for(int i=v[0];i<=v[1];i++){
                if(res.find(i)==res.end()){//表示set中没有这个元素
                    res.insert(i);
                    break;//这个区间结束
                }
            }
        }
        return res.size();
    }
};


//加一种使用数组的解法。。。个人感觉数组比set快

inline bool cmp(vector<int>&a,vector<int>&b){
    return a[1]<b[1];//最晚时间按照，从小到大排序
}
class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        vector<bool>vis(100001,false);
        sort(events.begin(),events.end(),cmp);
        int ans=0;
        for(auto v:events){
            for(int i=v[0];i<=v[1];i++){
                if(vis[i])continue;
                if(vis[i]==false){
                    vis[i]=true;
                    ans++;
                    break;
                }
            }
        }
        return ans;

    }
};
```
方法二：
```
//使用优先队列的方法。。。
class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end());
        priority_queue<int,vector<int>,greater<int>>pq;//小顶堆
        int ans=0,day=0;
        int i=0;
        while(!pq.empty()||i<events.size()){
            day++;
            while(pq.empty()==false&&pq.top()<day)pq.pop();//做一下清理工作将不符合条件的清理出优先队列
            while(i<events.size()&&events[i][0]==day){//将符合条件的放入到队列中
                pq.push(events[i][1]);
                i++;
            }
            if(pq.empty()==false){
                ans++;
                pq.pop();
            }
        }
        return ans;
    }
};
```

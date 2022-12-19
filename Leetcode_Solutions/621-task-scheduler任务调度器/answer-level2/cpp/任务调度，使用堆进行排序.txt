### 解题思路
1.首先统计每个任务出现的次数<任务，次数>
2.使用堆维护<次数，任务>对，次数最大的排在前面
3.每次从堆中取n+1个(冷却为n即一个区间最多n+1个不同任务)任务，考虑到最多只能取n+1个任务，记录执行的任务数num，对任务次数减一，若次数仍大于0，重新加入到堆中
4.若此时堆为空，说明最后执行了num个任务，结果+num，若堆不为空，无论执行了多少个任务，结果+(n+1)

### 代码

```cpp
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        typedef pair<int,char> pair;
        int res = 0;
        unordered_map<char,int> count;
        auto cmp =  [](pair& a,pair& b){return a.first < b.first;};//大顶堆
        priority_queue<pair,vector<pair>,decltype(cmp)> heap(cmp);
        for(auto t:tasks)
            ++count[t];
        for(auto& cnt:count)
            heap.push({cnt.second,cnt.first});
        while(!heap.empty()){
            stack<pair> s;
            int c = 0;
            for(int i = 0;i < n+1;++i){
                if(!heap.empty()){
                    pair p = heap.top();heap.pop();
                    ++c;
                    --p.first;
                    if(p.first>0) s.push(p);
                }
            }
            while(!s.empty()){
                heap.push(s.top());
                s.pop();
            }
            if(heap.empty()){
                res += c;
            }
            else{
                res += n+1;
            }
        }
        return res;
    }
};
```
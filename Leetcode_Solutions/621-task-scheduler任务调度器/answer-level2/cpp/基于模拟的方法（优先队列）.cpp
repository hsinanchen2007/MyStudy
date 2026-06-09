首先统计各种任务出现的次数，然后降序排序，出现次数>0的数入大根堆。

每次选取任务时，选剩余次数最多的执行（使任务种类数尽可能多，从而调度时利用率更高），然后减1暂存起来，等到间隔n过去后，再把暂存起来的输入push到大根堆中。重复此过程。

```c++
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if(n==0)
            return tasks.size();
        vector<int> vec(26,0);
        for(int i=0; i<tasks.size(); ++i)
            vec[tasks[i]-'A']+=1;
        sort(vec.begin(), vec.end(), greater<int>());
        priority_queue<int, vector<int>, less<int> > h1,h2;
        for(int i=0; i<vec.size()&&vec[i]!=0; ++i)
            h1.push(vec[i]);
        int time=0;
        while(!h1.empty()){
            int count=n+1;
            while(!h1.empty() && count){
                int tmp=h1.top()-1;
                if(tmp) h2.push(tmp);
                h1.pop();
                count--;
                time++;
            }
            if(h1.empty()&&h2.empty())
                break;
            while(count){
                time++;
                count--;
            }
            while(!h2.empty()){
                h1.push(h2.top());
                h2.pop();
            }
        }
        return time;
    }
};
```
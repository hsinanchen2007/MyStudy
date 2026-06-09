1. 首先记录每个课后面要修什么课，以及前面有多少课要修。
2. 每学期找到前面要修的课数量为0的未修读的课程，这学期修它！然后标记为已修读。
3. 每次修读一个课程i，课程i后面要修读的课的前置课程数量减一。
4. 如果某一个学期陷入死锁，剩余课都无法修读，那么返回-1.
5. 时间复杂度o(n),空间复杂度o(n^2).
```
class Solution {
public:
    int minimumSemesters(int N, vector<vector<int>>& relations) {
        //求得每个课的后续课程next[i],以及前面还有多少课要修pre[i]。
        vector<vector<int> > next(N);
        vector<int> pre(N,0);
        for(auto relation:relations)
        {
            next[relation[0]-1].push_back(relation[1]-1);
            pre[relation[1]-1]++;
        }
        //进行拓扑排序
        int term = 0;//学期数量
        int numClass = 0;//已经修完课程数量
        while(numClass < N)
        {
            term++;
            bool deadlock = true;
            vector<int> classTaken;
            for(int i = 0;i<N;i++)
            {
                if(pre[i] == 0)
                    classTaken.push_back(i);
            }
            for(auto i:classTaken)
            {
                numClass++;
                pre[i] = -1;
                deadlock = false;
                for(auto j:next[i])
                    pre[j]--;
            }
            if(deadlock)
                return -1;
        }
        return term;
    }
};
```

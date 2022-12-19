利用map的有序性。其最末尾值为其键最大值。
```
class MaxQueue {
public:
    queue<int> q;
    map<int,int> m;
    MaxQueue() {

    }
    
    int max_value() {
        if(q.empty())
        {
            return -1;
        }
        else{
            map<int, int>::iterator iter;
            iter = m.end();
            iter--;
            return iter->first;
        }
    }
    
    void push_back(int value) {
        q.push(value);
        if(m[value]>=1)
        {
            m[value]++;
        }
        else
        {
            m[value] = 1;
        }
    }
    int pop_front() {
        if(q.empty()) return -1;
        if(m[q.front()] == 1)
        {
            m.erase(q.front());
        }
        else{
            m[q.front()]--;
        }
        int res = q.front();
        q.pop();
        return res;
    }
};
```

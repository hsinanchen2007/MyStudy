### 解题思路
1.关键在于入队一个当前最大值后，在这个值出队之前该值都是最大值，之前入队的值对最大值没影响，不必保留在最大值队列中。详细的见官方题解。

2.最大值队列最好用双端队列，因为队首队尾都要弹出。我是vector模拟双端队列的。

### 代码

```cpp
class MaxQueue {
public:
    queue<int>q;
    vector<int>maxValue;
    int tail;
    MaxQueue() {
        tail=-1;
    }

    int max_value() {
        if(q.empty())return -1;
        return maxValue[0];
    }

    void push_back(int value) {
        q.push(value);
        while(tail>=0&&value>maxValue[tail])tail--;
        tail++;
        if(tail+1>maxValue.size())maxValue.push_back(value);
        else maxValue[tail]=value;
    }

    int pop_front() {
        if(!q.empty()){
            int temp=q.front();
            q.pop();
            if(temp==maxValue[0]){
                maxValue.erase(maxValue.begin());
                tail--;
            }
            return temp;
        }
        return -1;
    }
};
```
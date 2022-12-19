题目里说了操作总数不超过10000，因此10001大小的数组可以满足需求。

把所有push的value放进数组rec里，用两个整数start和end标记有效数据段。
据题意，若start==end，则队列为空，pop_front 和 max_value 需要返回-1。

数组maxr记录如果i之前的数据全部被pop掉，那么maxr[i]是应当输出的最大值。
据此，每个新的value被push入rec的同时也追加到maxr的队尾，并且覆盖掉之前比它小的所有value.

```
class MaxQueue {
public:
    int rec[10001];
    int maxr[10001];
    int start=0,end=0;
    MaxQueue() {
    }
    int max_value() {
        if(start==end)return -1;
        return maxr[start];
    }    
    void push_back(int value) {
        rec[end]=value;
        maxr[end]=value;
        if(end>0){
            int t=end-1;
            while(t>=start&&value>maxr[t]){
                maxr[t--]=value;
            }
        }
        end++;
    }
    int pop_front() {
        if(start==end)return -1;
        int a=rec[start];
        start++;
        return a;
    }
};
```

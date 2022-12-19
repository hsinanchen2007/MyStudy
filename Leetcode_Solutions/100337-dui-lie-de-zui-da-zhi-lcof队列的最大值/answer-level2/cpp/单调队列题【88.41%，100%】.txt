关于单调队列，这里看这篇博客：https://blog.csdn.net/no_O_ac/article/details/96976479

我也是偷懒，直接用 vector 和 deque 写的。

但实际上来说，用数组模拟 deque，以及用数组代替 vector 时间上会更优。因为 deque 确实慢。当然，一般都是竞赛才考虑这些。因为 stl 用起来确实方便。

然后，单调队列会了，这个题就没问题了。赋垃圾代码：

```c++
class MaxQueue {
public:
    MaxQueue() {
        while(!ddq.empty()) ddq.pop_back();
        myQue.clear();
        cnt = 0;
    }

    int max_value() {
        if(ddq.empty()) return -1;
        return myQue[ddq.front()];
    }

    void push_back(int value) {
        while(!ddq.empty() && myQue[ddq.back()] < value) ddq.pop_back();
        myQue.push_back(value);
        ddq.push_back(cnt ++);
    }

    int pop_front() {
        if(ddq.empty()) return -1;
        ++ fro;
        while(!ddq.empty() && ddq.front() <= fro) ddq.pop_front();
        return myQue[fro];
    }

private:
    vector<int> myQue;
    deque<int> ddq;
    int cnt = 0;    // 尾
    int fro = -1;    // 首
};
```

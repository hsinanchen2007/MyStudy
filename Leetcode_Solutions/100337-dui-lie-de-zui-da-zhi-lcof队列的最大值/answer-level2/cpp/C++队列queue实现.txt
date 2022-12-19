不知道这种写法是不是符合均摊时间复杂度O(1)，大家帮忙品一品，谢谢~
```
/*
*	FT:学习均摊时间复杂度
*	均摊时间复杂度是一种特殊的平均复杂度，利用摊还分析法
*	即把耗时多的复杂度均摊到耗时低的复杂度
*	例如每一次O(n)会紧跟n个O(1)出现，那么得到的均摊时间复杂度为O(1)
*	题解：用一个值Max记录当前队列的最大值
*	max_value：当队列为空时返回-1，否则返回Max，时间复杂度O(1)
*	push_back：调用queue的push，并打擂台更新Max，时间复杂度O(1)
*	pop_front：因为可能pop出Max，所以相对比较复杂。当出现这种情况时，调用scanMax从头到尾搜索最大值，时间复杂度O(n)
*	没这种情况时，直接pop，时间复杂度O(1)
*	因为O(n)出现的几率是1/n，而O(1)出现的几率是(n-1)/n，所以摊还分析得均摊时间复杂度为O(1)
*/

class MaxQueue {
public:
    MaxQueue() {

    }
    
    int max_value() {
        if(q.empty()) return -1;
        return Max;
    }
    
    void push_back(int value) {
        q.push(value);	// 注意push是压入队尾
        Max=max(Max,value);
    }
    
    int pop_front() {
        if(q.empty()) return -1;
        int tmp=q.front();	// 注意要用front，因为pop是删除第一个元素
        q.pop();	// 注意先pop，再检查是否最大元素，不然scanMax会把原本的Max元素也扫描到
        if(Max==tmp) Max=scanMax();
        return tmp;
    }

    int scanMax() {
        int s=q.size();
        int maxVal=INT_MIN;
        for(int i=0;i<s;i++){	// 进行n次front，pop和push
            int tmp=q.front();
            maxVal=max(maxVal, tmp);
            q.pop();
            q.push(tmp);
        }
        return maxVal;
    }

    private:
        queue<int> q;
        int Max=INT_MIN;
};
```

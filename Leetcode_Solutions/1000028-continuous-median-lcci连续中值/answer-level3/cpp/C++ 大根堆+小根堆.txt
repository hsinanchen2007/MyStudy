### 解题思路
大根堆和小根堆分别存储有序化后的输入数据的左右半部分的数字,则两个堆顶构成中位数

### 代码

```cpp
class MedianFinder {
public:
    priority_queue<int, vector<int>, less<int>> q_1;//大根堆，储存左半部分
    priority_queue<int, vector<int>, greater<int>> q_2;//小根堆，储存右半部分
    /** initialize your data structure here. */
    MedianFinder() {
    }
    void addNum(int num) {
        if(q_1.empty()){
            q_1.push(num);
            return;
        }  
        if(num <= q_1.top())
            q_1.push(num);
        else 
            q_2.push(num);
        //保持两个堆的大小差距不超过1
        while(int(q_1.size() - q_2.size()) > 1){
            q_2.push(q_1.top());
            q_1.pop();
        }
        while(int(q_2.size() - q_1.size()) > 1){
            q_1.push(q_2.top());
            q_2.pop();
        }
    }
    double findMedian() {
        int n1 = q_1.size();
        int n2 = q_2.size();
        if(n1 == n2)
            return double(q_1.top() + q_2.top()) / 2;
        else if(n1 > n2)
            return q_1.top();
        else   
            return q_2.top();
    }
};
```
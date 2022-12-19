### 解题思路

两个堆：
最大堆存放较小的一半数   最大堆的堆顶是较小一半数中最大的数
最小堆存放较大的另一半数 最小堆的堆顶是较大一半数中最小的数

则可以直接根据两个堆顶 计算出中位数

如果数据总数为偶数，则中位数为两个堆顶的平均值
如果数据总数为奇数，则为数据量大的堆的堆顶


### 代码

```cpp
class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }

    void addNum(int num) {

        if (m_max_queue.empty())
        {
            m_max_queue.push(num);
        }
        else
        {
            if (num <= m_max_queue.top()) //大堆放较小值
            {
                m_max_queue.push(num);
            }
            else //小堆放较大值
            {
                m_min_queue.push(num);
            }
        }

        //平衡数量
        if (m_max_queue.size() > m_min_queue.size() + 1)
        {
            m_min_queue.push(m_max_queue.top());
            m_max_queue.pop();
        }
        else if (m_min_queue.size() > m_max_queue.size() + 1)
        {
            m_max_queue.push(m_min_queue.top());
            m_min_queue.pop();
        }
    }

    double findMedian() {

        double median = 0.0;

        if ((m_max_queue.size() + m_min_queue.size()) % 2 == 0)
        {
            median = (m_max_queue.top() + m_min_queue.top()) / 2.0;
        }
        else if(m_max_queue.size() > m_min_queue.size())
        {
            median = m_max_queue.top();
        }
        else if (m_max_queue.size() < m_min_queue.size())
        {
            median = m_min_queue.top();
        }

        return median;
    }

private:
    priority_queue<int> m_max_queue; //最大优先队列
    priority_queue<int, vector<int>, greater<int>> m_min_queue;  //最小优先队列

};
/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
```
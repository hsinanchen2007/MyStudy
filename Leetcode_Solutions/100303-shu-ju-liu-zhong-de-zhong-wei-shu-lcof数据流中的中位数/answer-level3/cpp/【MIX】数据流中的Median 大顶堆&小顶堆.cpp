### 解题思路
设中位数为pivot, 维护两个堆, 中位数为堆顶元素考虑奇偶性加权计算

### 代码

```c++ []
class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        this->N = 0;
    }
    
    void addNum(int num) {
        // 默认进入最大堆
        pqMax.push(num);
        // 根据奇偶性进行调整
        if((N & 0x01)==0){
            if(pqMin.empty()){
                ++N;
                return;
            }
            else if(pqMax.top() > pqMin.top()){
                // swap
                int eMax = pqMax.top(); pqMax.pop();
                int eMin = pqMin.top(); pqMin.pop();
                pqMax.push(eMin);
                pqMin.push(eMax);
            }
        }
        else{
            pqMin.push(pqMax.top());
            pqMax.pop();
        }
        ++N;
    }
    
    double findMedian() {
        return N%2==0 ? (pqMax.top()+pqMin.top())/2.0 : pqMax.top();
    }

private:
    priority_queue<int, vector<int>, less<int>> pqMax; // 小于等于pivot的最大堆
    priority_queue<int, vector<int>, greater<int>> pqMin; // 大于pivot的最小堆
    int N;
    
};

```
```java []
class MedianFinder {

    /** initialize your data structure here. */
    // 维护两个动态堆
    // 设置中位数为pivot, 大于pivot的部分维护一个最小堆, 小于pivot的部分维护一个最大堆
    // assert 最大堆堆顶元素 < 最小堆堆顶元素
    private PriorityQueue<Integer> pqMax, pqMin;
    private int N = 0;
    
    public MedianFinder() {
        pqMax = new PriorityQueue<Integer>((Integer a, Integer b)->(b-a));
        pqMin = new PriorityQueue<Integer>();
    }
    
    public void addNum(int num) {
        pqMax.offer(num);
        // 如果当前元素的数量为偶数, 判断最小堆是否为空
        if((N & 0x01)==0){
            if(pqMin.isEmpty()){
                ++N;
                return;
            }
            // 检查堆条件是否满足, 如果不满足进行堆元素交换
            else if(pqMax.peek() > pqMin.peek()){
                int eMax = pqMax.poll();
                int eMin = pqMin.poll();
                pqMax.offer(eMin);
                pqMin.offer(eMax);
            }
        }
        // 当前元素数量为奇数
        else{
            pqMin.offer(pqMax.poll());
        }
        ++N;
    }
    
    // 中位数为偏小一侧的元素, 取最大堆的堆顶
    public double findMedian() {
        if((N & 0x01)==0)
            return (pqMin.peek()+pqMax.peek())/2.0;
        else
            return pqMax.peek();
    }
}

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */
```
```python []
from queue import PriorityQueue as PQ
class MedianFinder:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.pqMax = PQ() # 大顶堆
        self.pqMin = PQ() # 小顶堆
        self.N = 0


    def addNum(self, num: int) -> None:
        self.pqMax.put((-num, num))
        if (self.N & 0x01) == 0:
            if self.pqMin.qsize() == 0:
                self.N+=1
                return
            elif self.pqMax.queue[0][1] > self.pqMin.queue[0][1]:
                eMax, eMin = self.pqMax.get()[1], self.pqMin.get()[1]
                self.pqMax.put((-eMin, eMin))
                self.pqMin.put((eMax, eMax))
        else:
            e = self.pqMax.get()[1]
            self.pqMin.put((e, e))

        self.N+=1

    def findMedian(self) -> float:
        if self.N % 2==1:
            return self.pqMax.queue[0][1]
        else:
            return (self.pqMax.queue[0][1]+self.pqMin.queue[0][1])/2
```
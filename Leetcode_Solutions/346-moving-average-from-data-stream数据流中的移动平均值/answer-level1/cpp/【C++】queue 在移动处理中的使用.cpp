1.使用queue
2.如果在窗体范围中push
3.移出窗体pop
4.求max，average，min，sum随意

```
class MovingAverage
{
public:
    /** Initialize your data structure here. */
    MovingAverage(int size)
    {
        queueMaxSize = size;
        currentSum = 0;
    }

    double next(int val)
    {
        if (currentQueue.size() < queueMaxSize) {
            currentQueue.push(val);
            currentSum += val;
        } else {
            currentSum -= currentQueue.front();
            currentQueue.pop();
            currentQueue.push(val);
            currentSum += val;
        }
        return currentSum / currentQueue.size();
    }
private:
    int queueMaxSize;
    queue<int> currentQueue;
    double currentSum;
};
/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
```

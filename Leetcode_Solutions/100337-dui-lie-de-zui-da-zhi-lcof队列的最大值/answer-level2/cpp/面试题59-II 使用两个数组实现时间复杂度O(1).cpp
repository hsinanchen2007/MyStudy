### 解题思路
使用数组实现，效率不错。
以空间换时间。
![image.png](https://pic.leetcode-cn.com/dc8e8f01adcfa9aecf2c1ca3ce84b4bd540f67eca49c63c320b86ffa2f406691-image.png)

### 代码

```cpp
class MaxQueue {
public:
    MaxQueue() {}
    
    int max_value() {
        if (front == end)
            return -1;
        return myQueue[maxList[frontMaxList]];
    }
    
    void push_back(int value) {
        myQueue[end] = value;
        while (endMaxList-1 >= frontMaxList) {
            if (value >= myQueue[maxList[endMaxList-1]])
                endMaxList--;
            else
                break;
        }
        maxList[endMaxList++] = end;
        end++;
    }
    
    int pop_front() {
        if (front == end)
            return -1;
        else {
            if (front == maxList[frontMaxList])
                frontMaxList++;
            front++;
            return myQueue[front-1];
        }   
    }

private:
    int myQueue[10001], //存储队列元素
        maxList[10001]; //维护一个递减的最大值数组（存储队列元素的索引）
    int frontMaxList = 0, //最大值数组的前端索引
        endMaxList = 0, //最大值数组的后端索引（最后一个值的后一位）
        front = 0, //队列前端索引
        end = 0; //队列后端索引（最后一个值的后一位）
};
```
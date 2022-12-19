### 解题思路
startIndex 指向下次替换的标志 到尾部之后再从头开始
eg
startIndex, 添加值, startIndex
    0         1       1
    1         10      2
    2          3      0  一次轮回 下一又指向开头



### 代码 我的
35ms 56.68%
54.6MB 5.37%
```java
class MovingAverage {
    private int[] que;
    private int size;
    private int startIndex;
    private int all;
    /** Initialize your data structure here. */
    public MovingAverage(int size) {
        que = new int[size];
    }

    public double next(int val) {
        if (size < que.length) {size ++;}
        int old = que[startIndex];
        que[startIndex] = val;
        if (startIndex < que.length - 1) {
            startIndex ++;
        } else {
            startIndex = 0;
        }
        all = all - old + val;
        return (double) all/size;
    }
}

### 代码 别人的
25ms 100%
class MovingAverage {
    int[] queue;
    int headerIndex;
    int count;
    int size;
    int sum;

    MovingAverage(int size){
        this.size = size;
        queue = new int[size];
//        headerIndex = -1;
    }

    public double next(int value){
        if (size == count) {
            // todo:
            sum -= queue[headerIndex];
            headerIndex = (headerIndex + 1) % size;
            count--;
        }
        int tailIndex = (headerIndex + count) % size;
        queue[tailIndex] = value;
        sum += value;
        count++;
        
        return (double) sum/count;
    }
}

```
我不是很懂之间的区别 思路都是差不多的 2中有取余 我的没有 不是很懂
有没有大神告诉一下呀
### 解题思路
信号量实现，OS生产者消费者经典题，其中信号量的实现参考https://leetcode-cn.com/problems/the-dining-philosophers/solution/zhe-xue-jia-jiu-can-wen-ti-by-mike-meng/

### 代码

```cpp
class BoundedBlockingQueue {
public:
    BoundedBlockingQueue(int capacity) {
        empty.Set(capacity);
        full.Set(0);
    }
    
    void enqueue(int element) {
        empty.Wait();
        std::unique_lock<std::mutex> mutex_;
        queue_.push(element);
        full.Signal();
    }
    
    int dequeue() {
        full.Wait();
        std::unique_lock<std::mutex> mutex_;
        int ans = queue_.front();
        queue_.pop();
        empty.Signal();
        return ans;
    }
    
    int size() {
        return full.get();
    }
private:
class Semophore {
        public:
        Semophore(int count = 0): count_(count){}
        void Set(int count) {count_ = count;}
        void Signal() {
            std::unique_lock<std::mutex> lock(mutex_);
            ++count_;
            cv_.notify_one();
        }
        void Wait() {
            std::unique_lock<std::mutex> lock(mutex_);
            while (count_ <= 0) cv_.wait(lock);
            count_--;
        }
        int get() {
            std::unique_lock<std::mutex> lock(mutex_);
            return count_;
        }
        private:
        std::mutex mutex_;
        std::condition_variable cv_;
        int count_;
    };
Semophore empty;
Semophore full;
std::mutex mutex_;
queue<int> queue_;
};
```
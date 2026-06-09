### 解题思路
根据题目的性质自然可以想到单调栈的特性，这里自定义一个数据结构Node，一个存储节点key，另外一个存储在此节点前有多少小于key的节点。总的思路是用大的代表小的

### 代码

```cpp
struct Node{
    int key_; // 值是多少
    int num_; // 前面有多少个小于他的
};

class StockSpanner {
public:
    StockSpanner() {

    }
    int next(int price) {
        int sum = 0; // 前面比要插入元素小的数目，累加
        while(!stack_.empty() && stack_.top().key_ <= price){
            sum += stack_.top().num_;
            stack_.pop();
        }
        Node node = {price,sum+1};
        stack_.emplace(node);
        return stack_.top().num_;
    }
    stack<Node> stack_;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
```
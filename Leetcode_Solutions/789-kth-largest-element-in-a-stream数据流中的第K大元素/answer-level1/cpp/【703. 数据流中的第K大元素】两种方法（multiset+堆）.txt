## 思路一：multiset
利用set自动排序。
### 代码
```c++
class KthLargest {
    int K;
    multiset<int> st;
public:
    KthLargest(int k, vector<int>& nums) {
        for (int n : nums) {
            st.insert(n);
            if (st.size() > k) st.erase(st.begin());
        }       
        K = k;

    }
    
    int add(int val) {
        st.insert(val);
        if (st.size() > K) st.erase(st.begin());
        return *st.begin();
    }
};
```

## 思路二：堆
priority_queue<Type, Container, Functional>
Type为数据类型， Container为保存数据的容器，Functional为元素比较方式。
如果不写后两个参数，那么容器默认用的是vector，比较方式默认用operator<，也就是优先队列是大顶堆，队头元素最大，本题为小顶堆。
### 代码
```c++
class KthLargest {
    int K;
    priority_queue<int, vector<int>, greater<int>> pq;
public:
    KthLargest(int k, vector<int>& nums) {
        for (int n : nums) {
            pq.push(n);
            if (pq.size() > k) pq.pop();
        }       
        K = k;
    }
    
    int add(int val) {
        pq.push(val);
        if (pq.size() > K) pq.pop();
        return pq.top();
    }
};
```


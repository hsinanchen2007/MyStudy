### 解题思路
priority_queue<int> a; //大顶堆,默认是大顶堆  （降序）

priority_queue<int, vector<int>, greater<int> > c;//小顶堆 （升序）

![image.png](https://pic.leetcode-cn.com/53ff06bb43062bf9d4b66ebf6a032ce573cbeba5558211a28f0d852c241073cc-image.png)




### 代码

```cpp
class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> Q;
    int K;
    KthLargest(int k, vector<int>& nums) : K(k){
        for(auto x : nums){
            Q.push(x);
        }
    }
    
    int add(int val) {
        Q.push(val);
        while(Q.size() > K){
            Q.pop();
        }
        return Q.top();
    }

};

```
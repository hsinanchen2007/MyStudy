# Sort
```cpp
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if (stones.empty()) {
            return 0;
        }

        while (stones.size() != 1) {
            int n = stones.size();
            
            std::sort(stones.begin(), stones.end());
            stones[n - 2] = stones[n - 1] - stones[n - 2];
            stones.pop_back();
            std::cout << stones.size();
        }
        return stones[0];  
    }
};
```

# Priority_queue
```cpp
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // if (stones.empty()) {
        //     return 0;
        // }

        priority_queue<int> pq;
        for (int v : stones) {
            pq.push(v);
        }

        while (pq.size() > 1) {
            int w1 = pq.top();
            pq.pop();
            int w2 = pq.top();
            pq.pop();
            int remain = w1 - w2;
            if (remain) {
                pq.push(remain);
            }
        }
        return pq.size() == 1 ? pq.top() : 0;
    }
};
```
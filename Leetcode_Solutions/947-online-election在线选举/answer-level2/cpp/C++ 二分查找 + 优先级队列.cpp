1，优先级队列用于在预处理时确定每一个时刻的答案
2，二分查找寻找距离`t`最近的过去某个时刻的下标，然后取出答案即可
```
class TopVotedCandidate {
public:
    struct Vote {
        int person;
        int recent;
        int count;
        Vote(int p, int t, int c) : person(p), recent(t), count(c) {};
        Vote(int p, int t) : person(p), recent(t), count(0) {};
        bool operator < (const Vote& other) const {
            if (count == other.count) {
                return recent < other.recent;
            }
            return count < other.count;
        }
    };
    vector<int> results;
    vector<int> times;
    int N;
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        N = times.size();
        this->times = times;
        priority_queue<Vote> q;
        map<int, int> counts;
        for (int i = 0; i < N; ++i) {
            ++counts[persons[i]];
            q.push(Vote(persons[i], times[i], counts[persons[i]]));
            results.push_back(q.top().person);
        }
    }
    
    int index(int t) {
        int lo = 0;
        int hi = N - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo + 1) / 2;
            if (times[mid] > t) {
                hi = mid - 1;
            } else {
                lo = mid;
            }
        }
        return lo;
    }
    
    int q(int t) {
        return results[index(t)];
    }
};
```

![image.png](https://pic.leetcode-cn.com/906a7ba8f15847a93abf04c092f6648ad5f3e78d45ce0f8b6d804d249fc0a7fe-image.png)

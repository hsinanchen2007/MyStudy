一开始想得太复杂了。后面发现还是用简单的方法来
思路：先预处理数据，用一个数组记录下领先者有变化的时间点和当前的领先者。然后用二分遍历这个数组，找到一个大于t时间的index，那么index-1就是我们需要求的时间点，然后从数组中拿到index对应的数据，返回对应的领先者就行。

```
class TopVotedCandidate {
public:
    struct Vote {
        int person;
        int time;
        Vote(int p, int t) {
            person = p;
            time = t;
        }
    };
    vector<Vote> A;
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        map<int, int> countMap;
        int m = 0;
        int leader = -1;
        for(int i=0; i<persons.size(); i++) {
            auto p = persons[i];
            int c = 1;
            if (countMap.count(p) != 0) {
                c = countMap[p] + 1;
            }
            countMap[p] = c;
            if (m <= c) {
                if (p != leader) {
                    leader = p;
                    A.emplace_back(Vote(p, times[i]));
                }
                m = c;
            }
        } 
    }
    
    int q(int t) {
        int l = 1, r = A.size();
        while (l < r) {
            int mid = l + (r-l)/2;
            auto v = A[mid];
            if (v.time <= t) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return A[l-1].person;
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */
```
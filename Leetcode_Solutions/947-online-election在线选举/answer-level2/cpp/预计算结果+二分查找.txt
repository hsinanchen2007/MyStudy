### 解题思路
先预计算出全部时刻的胜利候选人存起来。
计算的时候只需要一个比persons长度大1的vector存储每个可能的候选人的选票数量。
因为每个时刻只会有一个候选人票数发生变化，所以可以记录一个历史最高票，然后每次进行比较，记录胜利者。
查找的时候，二分查找出<=t时刻的下标，然后直接取结果即可。
时间复杂度：n+logn。
空间复杂度：n

### 代码

```cpp
class TopVotedCandidate {
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) 
        :times_(times)
    {
        int pl = persons.size();
        vector<int> votes(pl+1,0);
        int max_vote = 0, max_voteid = -1;
        for(int i = 0, l = times.size(); i < l; i++)
        {
            if(++votes[persons[i]] >= max_vote)
            {
                max_voteid = persons[i];
                max_vote = votes[max_voteid];
            }
            winner_.push_back(max_voteid);
        }
    }
    
    int q(int t) {
        int c = upper_bound(times_.begin(), times_.end(), t)-times_.begin();
        c = c - 1;
        return winner_[c];
    }
private:
    vector<int>& times_;
    vector<int> winner_;
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */
```
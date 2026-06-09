因为用map写起来比较快就用了，虽然在空间利用上不够理想。

利用了map对key进行排序的特性。map的key表示区间左端点，value表示区间右端点。

每次addNum时，用二分搜索找到比当前加入数字大的区间左端点，此区间为加入点的右侧区间，上一个区间为左侧区间。

代码较短，很容易理解。
```c++
class SummaryRanges {
public:
    map<int,int> intervals;

    SummaryRanges() {
    }

    void addNum(int val) {
        auto post = intervals.upper_bound(val);
        auto prev = post;
        if(prev != intervals.begin())
            prev--;
        if(post == intervals.end() || post->first != val + 1){ // 无法加入右侧区间
            if(prev == intervals.end() || prev == post || prev->second < val - 1){ // 无法加入左侧区间
                // 创建一个区间
                intervals[val] = val;
            } else if(prev->second == val - 1){ // 和左侧区间正好相接
                // 加入前区间
                prev->second = val;
            }
        } else{ // 可以加入右侧区间
            if(prev == intervals.end() || prev == post || prev->second < val - 1){ // 无法加入左侧区间
                // 将右侧区间下界变为val
                intervals[val] = post->second;
                intervals.erase(post);
            } else{ // 和前区间相接
                // 合并两个区间
                prev->second = post->second;
                intervals.erase(post);
            }
        }
    }

    vector<vector<int>> getIntervals() {
        vector<vector<int>> res;
        for(auto i: intervals){
            vector<int> temp;
            temp.push_back(i.first);
            temp.push_back(i.second);
            res.push_back(move(temp));
        }
        return res;
    }
};
```
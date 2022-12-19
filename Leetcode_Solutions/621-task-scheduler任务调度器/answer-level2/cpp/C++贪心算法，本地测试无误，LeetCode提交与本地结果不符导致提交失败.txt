先创建一个哈希表，按value从大到小排序，然后遍历哈希表，即优先执行数量多的任务  
同时建立两个变量cnt_total（要返回的结果）和cnt_tmp（临时计数器），cnt_tmp初始化为n+1  
每次遍历时，将哈希表中对应的value减1，并将cnt_tmp减1，若遍历结束前cnt_tmp为0了，就提前结束本次遍历，开始下一次遍历；若遍历结束后cnt_tmp > 0，就等待cnt_tmp个时间，因此要将cnt_total += cnt_tmp  
结束遍历的条件为哈希表中value最大的项都已经为0  
当n为0时此方法不适用，因此做了单独讨论  
具体细节见代码：
```
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if (n > 0) {
            //建立哈希表并按value从大到小排序
            unordered_map<char, int> m;
            for (const auto &c : tasks)
                ++m[c];
            vector<pair<char, int>> tmp;
            for (const auto &i : m)
                tmp.push_back(i);
            sort(tmp.begin(), tmp.end(), 
                 [=](pair<char, int>& a, pair<char, int>& b)
                 { return a.second > b.second; });

            int cnt_total = 0, cnt_tmp = n + 1;
            while (m.cbegin()->second > 0) { //哈希表中value最大的项都已经为0则终止循环
                for (auto &i : m) {
                    if (i.second == 0) continue; //已不存在此类型的任务，不计数
                    if (cnt_tmp == 0) break; //冷却时间为0，提前终止遍历
                    --i.second;
                    ++cnt_total;
                    --cnt_tmp;
                }
                if (cnt_tmp > 0 && m.cbegin()->second > 0) {
                    cnt_total += cnt_tmp; //加上剩余冷却时间
                }
                cnt_tmp = n + 1; //为下一次遍历重置冷却时间
            }
            return cnt_total;
        }
        else return tasks.size();
    }
};
```
此代码我提交后无法通过，有一个测试用例为["A","A","A","A","A","A","B","C","D","E","F","G"]，2，我在我自己的IDE上运行是正确的值16，在LeetCode中输出为3导致解答错误，非常迷幻，希望有高人能找出原因
![Snipaste_2019-10-10_00-50-01.png](https://pic.leetcode-cn.com/cc3eb15c8f97e97d7d5bc1f8a27efdffd954fcd99cf6e883f707d1327453781d-Snipaste_2019-10-10_00-50-01.png)
没想出DP方法，提供一种哈希的思路，时间复杂度应该是O(n)+O(T)=O(max(n,T))
步骤：
1. 建立哈希表m，遍历clips，以片段起点作为key，结束点作为value，对于同起点的片段，保留结束点较大的值，这样相当于剔除了clips中所有同起点片段中结束点较小的片段，同时便于后续顺序遍历。
2. 先取出表中以0开头的clip(该片段必取)，用curEnd记录当前所取clip的结束点(开始是m[0])，然后进入循环：遍历curEnd之前的哈希表，记录最大结束点nextEnd。若大于curEnd，则curEnd=nextEnd，重置nextEnd，统计片段数+1；若小于等于curEnd，则无法继续拼接，退出循环。
3. 判断curEnd是否等于T，返回ans或-1。
```C++ []
class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        if (!T) return 0;
        map<int, int> m;
        int i = 0;
        while (i < clips.size()) { //遍历clips，建立哈希表，保留同起点片段中最大结束点
            vector<int> &clip = clips[i];
            m[clip[0]] = clip[1] > m[clip[0]] ? clip[1] : m[clip[0]];
            i++;
        }
        
        int ans = 1;
        int curEnd = m[0], nextEnd = -1;
        i = 1;
        while (curEnd < T && i <= curEnd) { //遍历哈希表，逐步搜索尽可能结束点大的可拼接片段
            if (m.count(i)) {
                nextEnd = m[i] > nextEnd ? m[i] : nextEnd;
            }
            i++;
            if (i > curEnd) {
                if (nextEnd > curEnd) {
                    curEnd = nextEnd;
                    nextEnd = -1;
                    ans++;
                }
                else break;
            }
        }
        //判断是否完成拼接
        if (curEnd >= T) return ans;
        else return -1;
    }
};
```


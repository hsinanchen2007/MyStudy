### 解题思路
暴力：按题目意思就是两个人一组。当有一组人没有配对的时候，直接找到这组其中一个人需要配对的人，然后让另外一个人和它需要配对的人交换位置。交换位置之后，剩下的两个人可能配对，也可能不配对。继续遍历没有配对的组。
代码实现就是
1、将每两个数拼成一对，放到map里面，注意这个map需要放两个，比如1和2，就在map里面放1->2 和 2->1 ，这样方便我们寻找需要配对的人。
2、找到之后，移除刚刚放到map的4组数据，然后判断剩余的2人是不是情侣，如果不是，那么他们组成2对数，塞回map里面。
3、循环遍历，直到所有人配对。
4、之所以可以这样干，是因为这种配对游戏，是不存在什么先后配对哪些组导致交换次数会更进一步减少的。只要每次交换都可以配对出1组，就是最好答案。

### 代码

```cpp
class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        if (row.size() <= 2) {
            return 0;
        }
        map<int, int> mmp;
        for (int i=0; i<row.size(); i+=2) {
            int _max, _min;
            if (row[i] > row[i+1]) {
                _max = row[i];
                _min = row[i+1];
            } else {
                _max = row[i+1];
                _min = row[i];
            }
            if (_max%2 != 1 || _max - _min != 1) {
                mmp[_max] = _min;
                mmp[_min] = _max;
            }
        }
        int res = 0;
        while (!mmp.empty()) {
            res++;
            auto first = mmp.begin()->first;
            auto second = mmp.begin()->second;
            int find;
            if (first%2==0) {
                find = first+1;
            } else {
                find = first-1;
            }
            auto other = mmp[find];
            mmp.erase(first);
            mmp.erase(second);
            mmp.erase(find);
            mmp.erase(other);
            if ((second > other && (second%2!=1 || second - other != 1)) || (second < other && (other%2!=1 || other - second != 1))) {
                mmp[second] = other;
                mmp[other] = second;
            }
        }
        
        return res;
    }
};
```
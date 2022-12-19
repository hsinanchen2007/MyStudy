- 看了几个别人的答案也是用的回溯的解法，但是它们的回溯过程是 1~high，2~high，...，9~high，多了很多不必要的搜索，而且找出来的步进数是无序的，最后还要 sort 一遍，有点鸡肋。
- 我先找到 low 和 high 的位数，每次回溯是确定深度的，假设 low 是三位数，high 是五位数，回溯过程是 101~989、1010~9898、10101~high，找出来的步进数本身就是有序的，后面不用再做 sort 这个过程。
- 其实可以搜索的起始点还是有点粗糙，可以优化的离 low 更近，有兴趣的朋友可以试一下。

***Talk is cheap. Show me the code.***
```cpp
class Solution {
public:
    vector<int> countSteppingNumbers(int low, int high) {
        //res.reserve(high); //理论上预先分配空间的话可以执行的更快，但是系统好像不给分配太多内存 orz
        if (low == 0) res.push_back(0);
        this->low = low;
        this->high = high;
        int maxDepth = digit(high);    // 获取 high 的位数
        for (int depth = digit(low); depth <= maxDepth; depth++) //这是关键，每一轮确定深度的回溯！
            for (int i = 1; i <= 9; i++)                            
                backtrack(depth, 1, i);
        return res;
    }

    void backtrack(int maxRound, int round, long cur) {
        if (isFinished) return;         // 提前停止，剪枝艺术
        if (round == maxRound) {
            if (low <= cur && cur <= high) {
                res.push_back(cur);
            } else if (cur > high) {
                isFinished = true;      // 只要找到一个比 high 大的值就可以停止了
            }
            return;
        }
        int last = cur % 10;

        // 下面两句不能换位置，这样可以保证找出来的步进数自然就是有序的
        if (last > 0) backtrack(maxRound, round+1, cur * 10 + last - 1);
        if (last < 9) backtrack(maxRound, round+1, cur * 10 + last + 1);
    }

    int digit(int num) {
        if (num == 0) return 1;
        int res = 0;
        while (num != 0) {
            num /= 10;
            res++;
        }
        return res;
    }

private:
    bool isFinished;
    int low;
    int high;
    vector<int> res;
};

```
![Xnip2020-02-25_00-05-58.jpg](https://pic.leetcode-cn.com/3f2ef37774b7566f84bc0d2174fb85d420da0ff3e60b6b6d0817d705c9ba43f2-Xnip2020-02-25_00-05-58.jpg)

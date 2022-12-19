如果只是求环是否存在，不用双指针的一个解法是从某个节点开始按照规则顺次遍历节点，并通过一个vector记录一下节点是否被访问过，如果访问过则说明环存在。
但这里有一个问题是，在每次的找环的过程里，可能会出现访问到之前找环的过程里标记的节点，所以visited记录的时候标记一下颜色，每次找环之后颜色+1.
判断一下最后终止的时候是访问到之前的颜色，还是当前的颜色，如果是之前的颜色，说明只是访问到了之前被确认不在环里的节点。也不用继续了。
如果发现环，还需要判断一下是否环内所有节点符号一致，即满足题目中环为同一个方向的约束。

不过还是快慢指针更优雅，回头需要重写一下。

[自己动手实现分布式缓存](https://github.com/wfnuser/burrow)
[我的题解](https://www.github.com/wfnuser/leetcode)
[我的github](https://www.github.com/wfnuser)
欢迎大家在github follow我 对分布式缓存感兴趣的可以看第一个项目，希望之后可以发布更多的玩具项目


代码如下：
```
class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        vector<int> visited(n, 0);
        vector<int> visitedBefore(n, 0);
        int color = 0;
        for (int i = 0; i < n; i++) {
            if (visited[i]) continue;
            color++;
            int slow = i;
            while(true) {
                if (visited[slow]>=1) break;
                visited[slow] = color;
                slow += nums[slow] + n*5000;
                slow %= n;
            }
            if (visited[slow] != color) continue;
            int len = 0;
            int begin = slow;
            int flag = nums[slow] > 0 ? 1 : -1;
            while(true) {
                slow += nums[slow] + n*5000;
                slow %= n;
                len++;
                if (nums[slow]*flag < 0) {break;}
                if (slow == begin) break;
            }
            if (nums[slow]*flag < 0) continue;
            if (len > 1) return true;
        }

        return false;
    }
};
```

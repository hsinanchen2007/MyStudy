最好的计算最大面积方式是从高点往低点推算，而递增栈满足这一条件，因为在出栈时，出栈元素顺序保证了从高到低的性质

遍历所有节点，单调递增时入栈，出现当前节点比栈顶节点高度小时，循环出栈并计算出栈部分所能达到的最大面积

出栈结束表明新增当前节点时可恢复单调递增条件，需要注意的是新增节点的宽度需要累加出栈块的宽度，填充面积

最大面积其实取决于短木板，也就是在出栈后，把出栈元素的高度拉齐做成新的元素入栈

最终会形成一个真正的单调递增栈，再通过全量出栈计算

[接雨水](https://leetcode-cn.com/problems/trapping-rain-water/)一题可参考，用递减栈

12ms 12.1M
--- wangtao HW-2020/2/16
```
// 扩展一下横排宽度不一样的情况
typedef struct Node {
    int width;
    int height;
    Node(int x, int y) : width(x), height(y) {};
} Node;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxarea = 0;
        stack<Node> s;
        int cur = 0;
        int n = heights.size();
        vector<Node> heightNode;

        for (int i = 0; i < n; i++) {
            heightNode.push_back(Node(1, heights[i]));
        }
        while(cur < n) {
            int tmpwidth = 0;
            while(!s.empty() && heightNode[cur].height < s.top().height) {
                Node topNode = s.top();
                s.pop();
                tmpwidth += topNode.width;
                maxarea = max(maxarea, tmpwidth * topNode.height);
            }
            s.push(Node(heightNode[cur].width + tmpwidth, heightNode[cur].height));
            cur++;
        }
        int tmpwidth = 0;
        while(!s.empty()) {
            Node topNode = s.top();
            s.pop();
            tmpwidth += topNode.width;
            maxarea = max(maxarea, tmpwidth * topNode.height);
        }
        return maxarea;
    }
};
```

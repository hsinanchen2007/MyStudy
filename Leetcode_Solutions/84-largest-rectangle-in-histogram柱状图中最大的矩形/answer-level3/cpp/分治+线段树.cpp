参考官方题解实现了不同的解法，思路可参考官方题解。

1. 分治+线段树 

```
typedef struct SegTreeNode {
    int start, end, minIndex;
    SegTreeNode *left, *right;
    SegTreeNode(int start, int end) {
        this->start = start;
        this->end = end;
        left = right = NULL;
    }
} * SegTree;

class Solution {
   public:
    int largestRectangleArea(vector<int>& heights) {
        if (heights.empty()) return 0;
        SegTree root = buildSegTree(heights, 0, heights.size() - 1);
        return findMaxArea(heights, root, 0, heights.size() - 1);
    }

    int findMaxArea(vector<int>& heights, SegTree root, int start, int end) {
        if (start > end) return -1;
        if (start == end) return heights[start];

        int minIndex = query(root, heights, start, end);
        int leftMax = findMaxArea(heights, root, start, minIndex - 1); // 求左边的面积
        int rightMax = findMaxArea(heights, root, minIndex + 1, end); // 求右边的面积
        int curMaxArea = (end - start + 1) * heights[minIndex]; // 当前的面积
        return max(curMaxArea, max(leftMax, rightMax));
    }

    int query(SegTree root, vector<int>& heights, int start, int end) {
        if (!root || end < root->start || start > root->end) return -1;
        if (start <= root->start && end >= root->end) return root->minIndex;

        int leftMin = query(root->left, heights, start, end);
        int rightMin = query(root->right, heights, start, end);
        if (leftMin == -1) return rightMin;
        if (rightMin == -1) return leftMin;
        return heights[leftMin] < heights[rightMin] ? leftMin : rightMin;
    }

    SegTree buildSegTree(vector<int>& heights, int start, int end) {
        if (start > end) return NULL;
        SegTree root = new SegTreeNode(start, end);
        if (start == end) {
            root->minIndex = start;
            return root;
        }

        int mid = start + (end - start) / 2;
        root->left = buildSegTree(heights, start, mid);
        root->right = buildSegTree(heights, mid + 1, end);
        root->minIndex =
            heights[root->left->minIndex] < heights[root->right->minIndex]
                ? root->left->minIndex
                : root->right->minIndex;
        return root;
    }
};
```

2. 单调栈

```
class Solution {
   public:
    int largestRectangleArea(vector<int>& heights) {
        if (heights.empty()) return 0;
        vector<int> leftMin = getLeftMin(heights);
        vector<int> rightMin = getRightMin(heights);

        int res = 0;
        for (int i = 0; i < heights.size(); i++) {
            res = max(res, heights[i] * (rightMin[i] - leftMin[i] - 1));
        }

        return res;
    }

    vector<int> getRightMin(vector<int>& heights) {
        vector<int> res(heights.size(), heights.size());
        stack<int> st;
        for (int i = 0; i < heights.size(); i++) {
            while (!st.empty() && heights[i] < heights[st.top()]) {
                int t = st.top();
                st.pop();
                res[t] = i;
            }
            st.push(i);
        }
        return res;
    }

    vector<int> getLeftMin(vector<int>& heights) {
        vector<int> res(heights.size(), -1);
        stack<int> st;
        for (int i = 0; i < heights.size(); i++) {
            while (!st.empty() && heights[i] <= heights[st.top()]) st.pop();
            if (!st.empty()) res[i] = st.top();
            st.push(i);
        }
        return res;
    }
};

```

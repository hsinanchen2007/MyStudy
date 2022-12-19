敲了个线段树，感觉难度还行 sum min max三种类型
```cpp
class SegmentNode {
public:
    int val;
    int start;
    int end;
    SegmentNode* left;
    SegmentNode* right;

    SegmentNode(int start, int end) {
        this->start = start;
        this->end = end;
        this->left = this->right = nullptr;
    }
};

class SegmentTree {
public:
    int treeType;
    SegmentNode* head;

    // 0 -> sum tree
    // 1 -> min tree
    // 2 -> max tree
    SegmentTree(vector<int>& input, int treeType = 0) {
        this->treeType = treeType;
        head = buildTree(input, 0, input.size() - 1);
    }

    SegmentNode* buildTree(vector<int>& input, int start, int end) {
        SegmentNode* newNode = new SegmentNode(start, end);
        if (start == end) {
            newNode->val = input[start];
            return newNode;
        }
        int mid = start + (end - start >> 1);
        newNode->left = buildTree(input, start, mid);
        newNode->right = buildTree(input, mid + 1, end);
        switch (treeType)
        {
        case 0:
            newNode->val = newNode->left->val + newNode->right->val;
            break;
        case 1:
            newNode->val = min(newNode->left->val, newNode->right->val);
            break;
        case 2:
            newNode->val = max(newNode->left->val, newNode->right->val);
            break;
        }
        return newNode;
    }

    int search(SegmentNode* cur, int start, int end) {
        int result;
        switch (treeType)
        {
        case 0:
            result = 0;
            if (start == cur->start && end == cur->end)
                return cur->val;
            if (start <= cur->left->end)
                result += search(cur->left, start, min(end, cur->left->end));
            if (end >= cur->right->start)
                result += search(cur->right, max(start, cur->right->start), end);
            break;
        case 1:
            result = INT_MIN;
            if (start == cur->start && end == cur->end)
                return cur->val;
            if (start <= cur->left->end)
                result = max(result, search(cur->left, start, min(end, cur->left->end)));
            if (end >= cur->right->start)
                result = max(result, search(cur->right, max(start, cur->right->start), end));
            break;
        case 2:
            result = INT_MAX;
            if (start == cur->start && end == cur->end)
                return cur->val;
            if (start <= cur->left->end)
                result = min(result, search(cur->left, start, min(end, cur->left->end)));
            if (end >= cur->right->start)
                result = min(result, search(cur->right, max(start, cur->right->start), end));
            break;
        }
        return result;
    }

    void update(SegmentNode* cur, int index, int value) {
        if (cur->start == cur->end) {
            cur->val = value;
            return;
        }
        int mid = cur->start + (cur->end - cur->start >> 1);
        switch (treeType)
        {
        case 0:
            if (index <= mid) {
                cur->val = cur->right->val;
                update(cur->left, index, value);
                cur->val += cur->left->val;
            }
            else {
                cur->val = cur->left->val;
                update(cur->right, index, value);
                cur->val += cur->right->val;
            }
            break;
        case 1:
            if (index <= mid) {
                cur->val = cur->right->val;
                update(cur->left, index, value);
                cur->val = min(cur->val, cur->left->val);
            }
            else {
                cur->val = cur->left->val;
                update(cur->right, index, value);
                cur->val = min(cur->val, cur->right->val);
            }
            break;
        case 2:
            if (index <= mid) {
                cur->val = cur->right->val;
                update(cur->left, index, value);
                cur->val = max(cur->val, cur->left->val);
            }
            else {
                cur->val = cur->left->val;
                update(cur->right, index, value);
                cur->val = max(cur->val, cur->right->val);
            }
            break;
        }
    }
};

class NumArray {
public:
    SegmentTree* stree;
    NumArray(vector<int>& nums) {
        if(nums.size())
            stree = new SegmentTree(nums);
    }
    
    void update(int i, int val) {
        stree->update(stree->head, i, val);
    }
    
    int sumRange(int i, int j) {
        return stree->search(stree->head, i, j);
    }
};
```

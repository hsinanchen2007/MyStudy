![image.png](https://pic.leetcode-cn.com/f05d891d1e8ab5c3c7d4f491c447e892d6d724b80eac808dcf97907a9e3c6da6-image.png)

不得不说，题目很难理解。。
具体思路看顶楼的把，不多说了。。

```
static auto pre =[] { std::ios::sync_with_stdio(false); cin.tie(nullptr); return nullptr;}();
class Solution {
public:
    Node* intersect(Node* quadTree1, Node* quadTree2) {
        if (quadTree1->isLeaf) {
            return quadTree1->val ? quadTree1 : quadTree2;
        }
        if (quadTree2->isLeaf) {
            return quadTree2->val ? quadTree2 : quadTree1;
        }
        quadTree1->topLeft = intersect(quadTree1->topLeft, quadTree2->topLeft);
        quadTree1->topRight = intersect(quadTree1->topRight, quadTree2->topRight);
        quadTree1->bottomLeft = intersect(quadTree1->bottomLeft, quadTree2->bottomLeft);
        quadTree1->bottomRight = intersect(quadTree1->bottomRight, quadTree2->bottomRight);
        if (quadTree1->topLeft->isLeaf && quadTree1->topRight->isLeaf && quadTree1->bottomLeft->isLeaf && quadTree1->bottomRight->isLeaf && quadTree1->topLeft->val && quadTree1->topRight->val && quadTree1->bottomLeft->val && quadTree1->bottomRight->val) {
            quadTree1->val = true;
            quadTree1->isLeaf = true;
            quadTree1->topLeft = nullptr;
            quadTree1->topRight = nullptr;
            quadTree1->bottomLeft = nullptr;
            quadTree1->bottomRight = nullptr;
        }
        return quadTree1;
    }
};
```

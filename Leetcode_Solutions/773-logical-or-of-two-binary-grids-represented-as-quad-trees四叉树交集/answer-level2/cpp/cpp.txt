```
class Solution {
public:
    Node* intersect(Node* quadTree1, Node* quadTree2) {
          if (quadTree1->isLeaf) return quadTree1->val ? quadTree1 : quadTree2;
          if (quadTree2->isLeaf) return quadTree2->val ? quadTree2 : quadTree1;
          Node *tl = intersect(quadTree1->topLeft, quadTree2->topLeft);
          Node *tr = intersect(quadTree1->topRight, quadTree2->topRight);
          Node *bl = intersect(quadTree1->bottomLeft, quadTree2->bottomLeft);
          Node *br = intersect(quadTree1->bottomRight, quadTree2->bottomRight);
          if (tl->val == tr->val && tl->val == bl->val && tl->val == br->val && tl->isLeaf && tr->isLeaf && bl->isLeaf && br->isLeaf) {
              return new Node(tl->val, true, NULL, NULL, NULL, NULL);
          } else {
              return new Node(false, false, tl, tr, bl, br);
          }
    }
};
```
```
class Solution {
public:
    Node* intersect(Node* quadTree1, Node* quadTree2) {
        if(quadTree1 == NULL || quadTree2 == NULL)
        {
            return NULL;
        }
        if(quadTree1->isLeaf)
        {
            if(quadTree1->val == true)
                return quadTree1;
            else
                return quadTree2;
        }
        else if(quadTree2->isLeaf)
        {
            if(quadTree2->val == true)
                return quadTree2;
            else
                return quadTree1;
        }
        quadTree1->topLeft = intersect(quadTree1->topLeft, quadTree2->topLeft);
        quadTree1->topRight = intersect(quadTree1->topRight, quadTree2->topRight);
        quadTree1->bottomLeft = intersect(quadTree1->bottomLeft, quadTree2->bottomLeft);
        quadTree1->bottomRight = intersect(quadTree1->bottomRight, quadTree2->bottomRight);
        if(quadTree1->topLeft->isLeaf && quadTree1->topRight->isLeaf && quadTree1->bottomLeft->isLeaf &&
            quadTree1->bottomRight->isLeaf && quadTree1->topLeft->val == quadTree1->topRight->val &&
            quadTree1->topLeft->val == quadTree1->bottomLeft->val &&
            quadTree1->topLeft->val == quadTree1->bottomRight->val)
        {
            quadTree1->val = quadTree1->topLeft->val;
            quadTree1->isLeaf = true;
        }
        return quadTree1;
    }
};
```

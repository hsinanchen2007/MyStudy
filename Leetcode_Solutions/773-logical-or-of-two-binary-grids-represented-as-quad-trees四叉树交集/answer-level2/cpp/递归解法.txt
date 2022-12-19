 ### 思路：
#### 构建四叉树，首先构建根节点，构建根节点，首先构建根节点下个4个子节点，每个子节点又可作为根节点继续构建。

#### 构建规则：
##### 已知四叉树A B 的两个节点 a b, 需要根据a,b构造相应的四叉树C的节点c。 可以分两种情况考虑

##### 1.a b 其中至少有一个节点为叶子节点：
- 如果a b 均为叶子节点，则返回一个new Node() 叶子节点，节点的val为 (a->val || b->val)
- 如果只有一个节点为叶子节点，假设a为叶子结点，b为非叶子节点。
   - 如果a->val == false, 则a的值对b不会产生影响，直接返回b；
   - 如果a->val == true,则b的值不会对a产生影响，b的所有叶子节点会全变为true，并且会合并成一个大节点（**题目中四叉树节点的定义：对于每个结点, 它将被等分成四个孩子结点直到这个区域内的值都是相同的**），合并结果其实和a一样，因此可以直接返回a。

##### 2. a b 均不为叶子节点  则创建一个非叶子节点c， c下的4个节点分别由a，b的4个子节点构造
- c = new Node(false, false, nullptr, nullptr, nullptr, nullptr);
- c->topLeft = f(a->topLeft, b->topLeft)
- c->topRight = f(a->topRight, b->right)
- ……


##### 3. 需要额外考虑
- 构造完节点c后，我们还需要考虑，是否需要把c合并成大节点（c下的子节点都是叶子节点，且val都相等）


![image.png](https://pic.leetcode-cn.com/d0f8b99ba6a135e127bf66f1968c56fe8f2492152d6a6047c1b11b4582eb3a71-image.png)


```
Node* intersect(Node* quadTree1, Node* quadTree2) {

        // 如果两个都到达叶子节点， 返回直接或结果
        // 如果一个是叶子节点 一个不是叶子节点
        // 如果是叶子节点的值为T， 直接返回叶子节点T
        // 如果叶子极点值为F， 则返回非叶子节点

        
        if(quadTree1->isLeaf || quadTree2->isLeaf){
            if(quadTree1 ->isLeaf && quadTree2->isLeaf){
                bool r = quadTree1->val || quadTree2->val;
                return new Node(r, true, nullptr, nullptr, nullptr, nullptr);
            }
            if(quadTree1->isLeaf){
                if(quadTree1->val == false)     return quadTree2;
                else                            return quadTree1;
            }else if(quadTree2->isLeaf){
                if(quadTree2->val == false)     return quadTree1;
                else                            return quadTree2;
            }
        }

        Node* c = new Node(false, false, nullptr, nullptr, nullptr, nullptr);
        c->topLeft = intersect(quadTree1->topLeft, quadTree2->topLeft);
        c->topRight = intersect(quadTree1->topRight, quadTree2->topRight);
        c->bottomLeft = intersect(quadTree1->bottomLeft, quadTree2->bottomLeft);
        c->bottomRight = intersect(quadTree1->bottomRight, quadTree2->bottomRight);

        //判断 如果四个节点都为叶子节点，且值都相等 则合并为一个主节点
        bool hebing = false;
        if(c->topLeft->isLeaf && c->topRight->isLeaf && c->bottomLeft->isLeaf && c->bottomRight->isLeaf){
            bool tag = c->topLeft->val;
            if(c->topRight->val == tag && c->bottomLeft->val == tag && c->bottomRight->val == tag){
                hebing = true;
            }
        }
        if(hebing){
            c->isLeaf = true;
            c->val = c->topLeft->val;
            c->topLeft = c->topRight = c->bottomLeft = c->bottomRight = nullptr;
        }

        return c;
    }
```

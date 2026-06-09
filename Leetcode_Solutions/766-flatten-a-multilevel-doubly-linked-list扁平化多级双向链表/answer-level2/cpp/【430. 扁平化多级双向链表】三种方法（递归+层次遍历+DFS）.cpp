## 思路一：递归
类似二叉树前序遍历。
### 代码
```c++
class Solution {
    Node *pre = nullptr;
public:
    Node* flatten(Node* head) {
        if (head == nullptr) return head;
        Node *next = head->next;
        if (pre != nullptr) {
            pre->next = head;
            head->prev = pre;
        }
        pre = head;
        flatten(head->child);
        head->child = nullptr;
        flatten(next);
        return head;
    }
};
```

## 思路二：层次遍历
1. 当前节点cur从head节点开始，每次移动一步。
2. 如果当前节点cur没有孩子节点，则移动到下一个节点继续判断，否则，设孩子节点为tmp，遍历孩子链表到尾节点，然后将尾节点与当前节点cur的下一个节点相连。通过这样做，我们将一个孩子链表添加到了主链表中。
3. 将当前节点与孩子节点相连
### 代码
```c++
class Solution {
public:
    Node* flatten(Node* head) {     
        if (head == nullptr) return head;   
        Node *prenode = nullptr;
        Node *curnode = head;
        Node *nextnode = nullptr;
        while (curnode != nullptr) {
            //1. 没有孩子节点
            if (curnode->child == nullptr) {
                curnode = curnode->next;
                continue;
            }
            //2. 有孩子节点，遍历到孩子节点最后一个节点
            Node *tmp = curnode->child;
            while (tmp->next != nullptr) {
                tmp = tmp->next;
            }
            //2.1 将孩子链最后一个节点和主链下一个节点相连
            tmp->next = curnode->next;
            if (curnode->next != nullptr) {
                curnode->next->prev = tmp;
            }
            //2.2 当前节点与孩子节点相连，并重置当前节点孩子节点为空
            curnode->next = curnode->child;
            curnode->child->prev = curnode;
            curnode->child = nullptr;
        }
        return head;
    }
};
```
#### 另一种写法
```c++
class Solution {
public:
    Node* flatten(Node* head) {     
        if (head == nullptr) return head;   
        Node *curnode = head;
        while (curnode != nullptr) {
            //存在孩子节点
            if (curnode->child != nullptr) {
                Node *nextnode = curnode->next;//保存主链下一个节点
                //1. 链接主链节点和孩子节点
                curnode->next = curnode->child;
                curnode->child->prev = curnode;
                curnode->child = nullptr;
                //2. 找孩子链最后一个节点
                Node *p = curnode->next;
                while (p->next) p = p->next;
                //3. 将孩子链最后一个节点和主链下一个节点连接
                p->next = nextnode;
                if (nextnode) nextnode->prev = p;//下一个节点不为空，才设置前指针
            } else {
                curnode = curnode->next;
            }
        }
        return head;
    }
};
```

## 思路三：DFS（最优解）
### 代码
```c++
class Solution {
public:
    Node* flatten(Node* head) {        
        if (head == nullptr) return head;
        stack<Node*> st;
        st.push(head);
        Node *pre = nullptr;
        while (!st.empty()) {
            Node *p = st.top();
            st.pop();
            if (p->next != nullptr) {
                st.push(p->next);
            }
            if (p->child != nullptr) {
                st.push(p->child);
                p->child = nullptr;
            }
            if (pre != nullptr) {
                pre->next = p;
                p->prev = pre;
            }
            pre = p;
        }
        return head;
    }
};
```

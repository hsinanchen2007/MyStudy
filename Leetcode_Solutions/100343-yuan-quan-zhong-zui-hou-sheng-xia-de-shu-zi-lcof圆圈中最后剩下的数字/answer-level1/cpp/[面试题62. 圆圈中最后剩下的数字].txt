## 【解法一】链表模拟（超时）
#### 分析
单纯的模拟，超时了。
```
class Solution {
public:
    struct node {
        int num;
        node* next;
    };
    int lastRemaining(int n, int m) {
        node* final = new node;
        final->num = n - 1;
        node* x = final;
        for (int i = n - 2; i >= 0; i--) {
            node* n = new node;
            n->num = i;
            n->next = x;
            x = n;
        }
        final->next = x;
        node *tmp = x;
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < m - 1; j++) {
                tmp = x;
                x = x->next;
            }
            tmp->next = x->next;
            x = x->next;
        }
        return x->num;
    }
};
```
## 【解法二】递归
#### 分析
f(n, m)表示最终n个数，间隔m，剩下的数字在原来0..n-1中的下标。
考虑一个性质，对于任意一个f(n, m)，起点均为0（下标）。若起点偏移，假设偏移量为d，则f'(m, n) = ((d + f(m, n))) % n。也即，终点随起点偏移而偏移。循环队列来说，这是显而易见的性质。
考虑f(n - 1, m)，起点为0，终点为f(n - 1, m)。再分析f(n, m)，第一次删除的是数(m - 1) % n，第二次删除的起点就是(m - 1) % n + 1。
找递推关系的问题转化为：
起点：0   --->   终点：f(n - 1, m)
起点：(m - 1) % n + 1   --->   终点：？
显然，f(n, m) = ((m - 1) % n + 1 + f(n - 1, m)) % n
递推关系找到了。
```
class Solution {
public:
    int lastRemaining(int n, int m) {
        if (n == 1) {
            return 0;
        }
        else {
            return ((m - 1) % n + 1 + lastRemaining(n - 1, m)) % n;
        }
    }
};
```

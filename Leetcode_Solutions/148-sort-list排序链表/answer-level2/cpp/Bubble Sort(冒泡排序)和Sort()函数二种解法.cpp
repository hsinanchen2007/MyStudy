尽管冒泡排序在时间复杂度上并不占优势,但是确是最简单易懂的,那么具体的代码如下:
```
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        else {
            for (ListNode* i = head; i != NULL; i = i->next) {
                for (ListNode* j = i->next; j != NULL; j = j->next) {
                    if (i->val > j->val)
                        swap(i->val, j->val);
                }
            }
            return head;
        }
    }
};
```
那么我们可以看到对应的结果
![TIM图片20191211141822.png](https://pic.leetcode-cn.com/55f0ba3683a08c4476794855da63725d781674f9f0ebf70a75eeabc714e2ec59-TIM%E5%9B%BE%E7%89%8720191211141822.png)
当然我们也可以借助vector和sort()函数来解答,代码如下:

```
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        else {
            vector<int>arr;
            int j = 0;
            for (ListNode* i = head; i != NULL; i = i->next)
                arr.push_back(i->val);
            sort(arr.begin(), arr.end());
            for (ListNode* i = head; i != NULL; i = i->next,j++)
                i->val = arr[j];
            return head;
        }
    }
};
```
运行结果:
![TIM图片20191211141835.png](https://pic.leetcode-cn.com/b97302fb08bf31bf83a1396b536f74cb2b0b15c8be7609286638512414bdfd86-TIM%E5%9B%BE%E7%89%8720191211141835.png)

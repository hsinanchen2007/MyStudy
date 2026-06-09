第一次写中等难度，完了近两个小时，终于完成了。
![Image x.png](https://pic.leetcode-cn.com/d9f14d60d0ff76beb62a4919b3ac7000efc4ffff2417ae03fe86f7c444d7fce7-Image%20x.png)
### 解题思路
我采用用的是蛮干法（小学生加法运算思想）。先从基本情况1：【l1和l2长度相等且不进位】开始处理
然后分别处理l1长或l2长时候的加法（包含可能进位需要申请新的空间）。

中间有很多地方可以直接return，时间可以更短一些，但我没写了。
最终一次提交就通过，很开心。
### 代码

```c
/**
 * Definition for singly-linked list->
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l0, struct ListNode* l2){
    if(l0==NULL) return l2;
    if(l2==NULL) return l0;
    struct ListNode *l1 = l0,*prior=NULL;   //prior为l1的前继指针，这个用于后续申请空间，保存null前的结点
    int add_num=0,sum;
    while(l1!=NULL&&l2!=NULL){      //情况1: l1和l2长度一样,且不进位
        sum = l1->val+l2->val+add_num;
        l1->val = sum%10;
        add_num = sum/10;    //进位数
        prior = l1;         
        l1=l1->next;l2=l2->next;
    }
    if(l1==NULL||l2==NULL){   //这个if好像没用
        while(l2!=NULL){       //情况2: l2比l1长
            if(l1==NULL) prior->next=(struct ListNode*)malloc(sizeof(struct ListNode));//申请节点，分配给l1
            prior->next->next= NULL;    //必需，malloc必须声明其next指针指向，否则异常
            l1=prior->next;
            l1->val = (l2->val+add_num)%10;
            add_num = (l2->val+add_num)/10;
            l1=l1->next;l2=l2->next;prior=prior->next;
        }
        if(add_num!=0&&l1==NULL){   //情况2-1: l2比l1长之最后一个数进位与否问题（如：1+999）
            prior->next=(struct ListNode*)malloc(sizeof(struct ListNode));
            prior->next->next= NULL;    //必需，malloc必须声明其next指针指向
            l1=prior->next;
            l1->val = add_num;
            add_num = add_num/10;
            l1=l1->next;prior=prior->next;
        }
        while(l1!=NULL&&add_num!=0){     //情况3: l1比l2长
            sum = l1->val+add_num;
            l1->val = sum%10;
            add_num = sum/10;
            l1=l1->next;prior = prior->next;
        }
        if(add_num!=0&&l1==NULL){       //情况3-1: 进位超过长度，申请新空间
            prior->next = (struct ListNode*)malloc(sizeof(struct ListNode));
            prior->next->next = NULL;
            l1=prior->next;
            l1->val = add_num;
        }
    }
    return l0;
}
```
心得体会：
1. 将简单情况写在前面提前return会大大减少整体用时。
2. 对复杂问题不要心急，不要企图一次解决所有情况，要一步一步来，写好一个情况要回头自己编写相应的测试用例，看是否有解决了这种情况，没问题再往下写。
3. malloc的结构体中若包含指针，必须对该指针赋初值（即使时NULL）。

ps:整体可分为:
- 情况1
- 情况2+情况2-1(可选)
- 情况3+情况3-1(可选)
#### 先上提交结果图：
![交换节点.png](https://pic.leetcode-cn.com/1fb63556a71f404c87783d87e1d8a51596b6500cd5d2b1475ad872b148aa098a-%E4%BA%A4%E6%8D%A2%E8%8A%82%E7%82%B9.png)
#### 思想
    动手画图，搞清楚交换的原理。
####实现图：
    接下来画一下我写的草稿：
    1. 首先建立一个fakeHead为最头节点，它的next指向head。
    2. 为了完成交换，我们需要建立四个辅助的节点：pre为上一个遍历的节点；ptr为当前遍历的节点；temp为ptr的下一个节点——也就是要与ptr交换的节点；next为temp的下一个节点——也就是下一个要遍历的节点，比如1->2->3->4初始状态如下图：（这里有个有意思的点：为什么temp的下一个节点next是下一个需要遍历的点？拿下图来说，由于ptr(1)和temp(2)是需要交换的，交换完毕后，ptr的下一个点自然而然就变成了next了）
![begin.jpg](https://pic.leetcode-cn.com/96d67732a4fa81808afe34da28e1dc98d9fca7a9b889708c9a87ab9030310e56-begin.jpg)
    3. 接下来进行变换。
       - 第一步切断pre(fakeHead)和ptr(1)的连接，将pre(fakeHead)的下一个指向temp(2)节点
       - 第二步切断ptr(1)和temp(2)的连接，将ptr(1)的下一个指向next(3)节点
       - 第三步切断temp(2)和next(3)的连接，将temp(2)的下一个指向ptr(1)节点
       变换过程以及变换后的图如下：
![1.jpg](https://pic.leetcode-cn.com/24135e9df04db51112044f1fe419f1db3ae79e2d4eaae87ca7d378b6e621ab3e-1.jpg)
    4. 最后当然是重新设置四个辅助的节点，pre变成ptr,ptr变成next。开始新一轮的变换，如下图所示
![2.jpg](https://pic.leetcode-cn.com/4f8f9d16954803d50c05b6db21566a64019d1a3988b6ba6dd8256326c02e2414-2.jpg)
#### 最后附上源代码，配合代码的注释可能更好理解：
```
class Solution {
    public ListNode swapPairs(ListNode head)
    {
        ListNode fakeHead=new ListNode(0);
        fakeHead.next=head;
        ListNode pre=fakeHead;//前一个遍历的节点
        ListNode ptr=pre.next;//当前节点
        
        while(ptr!=null&&ptr.next!=null)
        {
            ListNode temp=ptr.next;//要与ptr交换位置的节点
            ListNode next=temp.next;//下一个要遍历的节点，先存储起来
            pre.next=temp;//因为pre是上一个的节点，所以需要连接下一个被交换后的节点
            temp.next=ptr;//交换节点
            
            pre=ptr;
            ptr=next;
        }
        pre.next=ptr;//！！很重要，最后的连接整理

        return fakeHead.next;
    }
}
```
# 最后。。。
    我是新人一个，此题是完全由自己手动画图写代码的，有什么说的不好的，欢迎指出！

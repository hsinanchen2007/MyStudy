希望自己以后回头看，能够发现自己是进步的。
还有一件事，说重点。就是迭代过程中遇到空指针的情况。

一开始 我设置的循环条件是这样的 ：
![image.png](https://pic.leetcode-cn.com/78278e0cc1ad2d7b013bc160dfd8dd1180eb27b92c0c2f55a50b0aed63348576-image.png)
然后超时了；
可能在循环体内部多了一个判断条件的原因；
发现

while(first && second)
{
    ...
    内部需要跨越3个节点；first->next->next->next;
}

自然这种情况下，就会存在first->next为空的情况；导致first->next->next出错，更别提first->next->next->next了；
因此，为了避免这种情况；参考官方解法进行调整。
![image.png](https://pic.leetcode-cn.com/ef49f567ba2437700a0552cea06bfd23cee834f60609e459a6095f26a9dcf0c7-image.png)


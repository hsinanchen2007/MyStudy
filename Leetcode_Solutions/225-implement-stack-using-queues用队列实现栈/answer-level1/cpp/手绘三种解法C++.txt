      这是我第二次发题解，希望大家支持下哈
      声明小萌新手机很渣，拍摄清晰度有限

# 解法一  
两队列，Push时间复杂度O(n),Pop时间复杂度O(1)

![图片.png](https://pic.leetcode-cn.com/25c19ea15c306adf11e21311edbb0343abdc4ec7c11e367a051461ab3ec61924-%E5%9B%BE%E7%89%87.png)

如果我们单单从操作的角度看，如图所示队列和栈只有Push是不一样的（队列插在队尾，栈插在栈顶）。
因此可以借助先将原队列中的值存入额外的临时队列temp，然后插入新元素，再将原本存在temp中的数据再导入原队列中。

![图片.png](https://pic.leetcode-cn.com/43fb9e60524c2b9200504c42ea6559bb4ebe5aa278f37ec405f6f24f18856085-%E5%9B%BE%E7%89%87.png)
![图片.png](https://pic.leetcode-cn.com/99e6d60701bb5e7456a022faa99a4a662b3c359d66c4222e2f3608aa6724a223-%E5%9B%BE%E7%89%87.png)

这里我们可以发现将一段有序序列**依次传入队列**中，**再依次传出队列**，**顺序不发生任何改变**
一段有序序列**依次传入栈**中，**再依次传出栈**，**顺序完全颠倒**
```
class MyStack {
private:
    queue<int> que;
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        queue<int> temp;
        int t=0;
        int length=que.size();
        for(int i=0; i<length; i++)
        {
            t=que.front();
            que.pop();
            temp.push(t);
        }
        //     temp.push(que.pop());
        que.push(x);
        // cout<<x<<" ";
        for(int i=0; i<length; i++)
        {
            t=temp.front();
            que.push(t);
            temp.pop();
           // cout<<t<<" ";
        }
        //cout<<endl;
        //     que.push(temp.pop());
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        if(que.empty())
            return 0;
        int t=que.front();
        que.pop();
        return t;
    }
    
    /** Get the top element. */
    int top() {
        if(que.empty())
            return 0;
        return que.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return que.empty();
    }
};

```
# 解法二
借助额外队列，Pop时间复杂度O(n),Push时间复杂度O(1)

![图片.png](https://pic.leetcode-cn.com/fd8570783a14d67631fbb6796191df967d15a86b03a621f4db7fd62661ec638b-%E5%9B%BE%E7%89%87.png)

有了上面的经验，我们不难发现，队列和我像构建的栈之间只有Pop操作不一样（和解法一非常相似）
**并且我们发现队列与栈的方向，会导致Pop和Push复杂度改变**

代码实现就当是小作业，由你自己完成

# 解法三
不借助额外队列，Push时间复杂度O(n)，Pop时间复杂度O(1)

![图片.png](https://pic.leetcode-cn.com/43fb9e60524c2b9200504c42ea6559bb4ebe5aa278f37ec405f6f24f18856085-%E5%9B%BE%E7%89%87.png)

**本质上是前两解法的优化**
利用前面提到的队列**顺序输入顺序输出不改变序列顺序**

![图片.png](https://pic.leetcode-cn.com/aa8932b8a53a7f9dca1c7dfa0d606a162c356612d727a4a3efa76382b3990242-%E5%9B%BE%E7%89%87.png)

也就是说**先将目标值插入**，**再将目标值前面的n-1个数输出再输入进入队列**,
这样前n-1个数都顺序的排列再目标值之下了

```
class MyStack {
private:
    queue<int> que;
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        //queue<int> temp;
        int t=0;
        int length=que.size();
        que.push(x);
        for(int i=0; i<length; i++)
        {
            t=que.front();
            que.pop();
            que.push(t);
        }
        //     temp.push(que.pop());
        // cout<<x<<" ";
        //cout<<endl;
        //     que.push(temp.pop());
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        if(que.empty())
            return 0;
        int t=que.front();
        que.pop();
        return t;
    }
    
    /** Get the top element. */
    int top() {
        if(que.empty())
            return 0;
        return que.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return que.empty();
    }
};
```






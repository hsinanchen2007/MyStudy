## 思路
将一个队列当做一个栈，队首元素视为栈底元素。  
`queue<int> q;`
**入栈操作** 即在队列尾端push()一个元素。时间复杂度 O(1)
```
    void push(int x) {
        q.push(x);
    }
```
**判断是否为空** 得到队列的长度，如果为零，则栈为空
```
    bool empty() {
        if(q.size() == 0)
            return true;
        return false;
    }
```
**得到栈顶元素** 等价于得到队列中的队尾元素
```
    int top() {
        return q.back();
    }
```
**栈顶元素出栈并返回其值** 返回其值同上一个操作，出栈操作：利用循环，将队列中的前 n - 1 个元素出队列并入队列，最后再将此时的队首元素出队列 时间复杂度O(n)
```
    int pop() {
        int len = q.size();
        int res = q.back();
        while(len - 1)
        {
            int temp = q.front();
            q.pop();
            q.push(temp);
            len--;
        }
        q.pop();
        return res;
    }
```

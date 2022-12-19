
实际就是模拟这个入栈与出栈过程
* 先根据入栈序列入栈；
* 如果栈顶元素是出栈元素(按顺序遍历)，出栈，直到不能再出栈；
* 继续入栈，重复前两步直到遍历完入栈序列；
* 比较是否能够出栈；
* 返回栈是否为空即可。



```
bool validateStackSequences(vector<int>& pushV, vector<int>& popV) {
        if(popV.empty() && pushV.empty())
            return 1;
        if(popV.empty() || pushV.empty())
            return 0;
        int pushOrd = 0, popOrd = 0;  // 遍历记录
        stack<int> V;
        for (pushOrd = 0, popOrd = 0; pushOrd < pushV.size(); ++pushOrd)  // 按顺序遍历
        {
            V.push(pushV[pushOrd]);  // 入栈
            while (!V.empty() &&popV[popOrd] == V.top())  // 如果栈顶元素等于出栈元素
            {
                V.pop();   // 出栈
                popOrd += 1;  // 向后移
            }
        }
        // 全部入栈完毕，如果栈为空，直接返回
        
        while (!V.empty() && V.top() == popV[popOrd])
        {
            V.pop(); 
            popOrd += 1;
        }

        return V.empty();
    }
```
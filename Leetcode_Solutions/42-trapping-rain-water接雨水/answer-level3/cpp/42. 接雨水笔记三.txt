### 解题思路
1. 使用单调递减栈来实现
2. void pop(); 弹出（即删除）栈顶元素
3. T & top(); 返回栈顶元素的引用。通过此函数可以读取栈顶元素的值，也可以修改栈顶元素
4. void push (const T & x); 将 x 压入栈顶，实际上是复制了一份x到stack

变量其实只不过是程序可操作的存储区的名称。
介绍关于普通变量、引用变量和指针变量的区别
1. 普通变量：int a3 = a1; // 赋值语句，可以理解成数据的克隆，a3与a1 不在是指向一个对象
2. 引用变量：int &b = a1; // b和a1指向同一个对象
3. 指针变量：int *c = &a1; // c存储的是a1对象的地址

### 代码

```cpp
class Solution {
public:
    int trap(vector<int>& height) {
        // 使用单调递减栈来实现
        int ans = 0;
        stack<int> s;
        int current = 0;
        while (current < height.size()) {
            while (!s.empty() && height[current] > height[s.top()]) {
                int top = s.top();
                s.pop();
                if (s.empty()) break;
                int len = current - s.top() - 1;
                int h = min(height[current], height[s.top()]) - height[top];
                ans += len * h;
            }
            s.push(current++);
        }

        return ans;
    }
};
```
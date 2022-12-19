
```
class MinStack {
        private:
        // 定义栈顶指针
        int topp;
        // 定义栈能存储最多元素个数
        int maxSize;
        // 定义顺序栈，用一维数组实现
        int *elements;
    
    public:
              
        /** initialize your data structure here. */
        MinStack() {
            // 定义一个构造函数初始化书需个变量
            // 初始化栈顶指针 topp = -1, 表示栈为空
            topp = -1;
            // 假设改栈能存储的最大元素个数为 200
            //maxSize = 500; 稍微大一点，如果用 500 会出错
            maxSize = 1000;
            // 初始化栈空间
            elements = new int[maxSize];

        }
        // 将元素 x 推入栈中。
        void push(int x) {
            // 先判断栈满否，满则元素不能进栈，返回结束
            if(topp == maxSize - 1) return;
            // 栈不满，元素进栈，栈顶指针先加 1 再进栈
            topp = topp + 1;
            elements[topp] = x;
        }
        // 删除栈顶的元素。
        void pop() {
            // 先判断栈是否为空，为空则没有元素可删除，返回结束
            //if(topp == -1) return ;
            // 如果栈不为空，则删除栈顶元素,栈顶指针减 1 
            topp = topp - 1;
        }
        //  获取栈顶元素。
        int top() {
            // 先判断栈是否为空，为空则没有元素可获取，返回结束
            //if(topp == -1) return 0;
            // 如果栈不为空，返回栈顶元素
            if(topp == -1) return NULL;
            return elements[topp];

        }

        int getMin(){
            // O(n) 的时间复杂度
            if(topp == -1) return NULL;
            int min = elements[0];
            for(int i = 1; i <= topp; i++){
                if(min > elements[i])
                    min = elements[i];
            }
            return min;
        }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
```

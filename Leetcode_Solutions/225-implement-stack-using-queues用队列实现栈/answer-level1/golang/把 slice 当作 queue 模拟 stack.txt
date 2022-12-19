# 涉及知识点

1. queue 先进先出
2. stack 后进先出

## 操作方法

1. 创建两个 queue
2. 模拟 stack 的 pop 操作时，可先将 data 队列元素出队，同时入队到 temp 临时队列
3. 当 data 队列只剩下最后一个元素时，就是 stack 的栈顶元素了，满足后进先出


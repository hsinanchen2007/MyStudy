### 解题思路
 1. 用队列来模拟栈
 2. 基本思路：
     1.预想存储两个队列，分 主 和 次
     2.压数据，一定是先入 次 ，次有内容，则压入后还需放一个到 主
     3.弹数据，一定是弹 次，次没有，那么就交换主，次，把次的其它元素移动到主，再弹次
     4.检测栈顶，一定是看 次，次没有，一样的交换操作，再 看次
     5.判空，则是检查两个队列的数据量
     
 3. 各操作复杂度判断：
     1.push --> O(1) 最好情况操作1次，最坏情况 操作2次，都是常量级
     2.pop --> O(n) 最好情况操作1次，最坏情况 操作n次，相当于把所有结果都倒腾了一遍
     3.top --> O(n) 同pop的情况
     3.Empty --> O(1) 利用了队列原有的特质

### 代码
```csharp []
        public class MyStack
        {

            private Queue<int> m_masterQueue;
            private Queue<int> m_slaveQueue;

            /// <summary>
            /// 将一个队列的元素，移动到另一个队列中，原始队列需要保留一个元素
            /// </summary>
            private void QueueElementMove(Queue<int> queueFrom, Queue<int> queueTo)
            {
                while (queueFrom.Count > 1)
                    queueTo.Enqueue(queueFrom.Dequeue());
            }

            /// <summary>
            /// 交换 master slave 队列
            /// </summary>
            private void SwapMasterSlave()
            {
                var temp = m_masterQueue;
                m_masterQueue = m_slaveQueue;
                m_slaveQueue = temp;
            }

            /** Initialize your data structure here. */
            public MyStack()
            {
                m_masterQueue = new Queue<int>();
                m_slaveQueue = new Queue<int>();
            }

            /** Push element x onto stack. */
            public void Push(int x)
            {
                m_slaveQueue.Enqueue(x);
                QueueElementMove(m_slaveQueue, m_masterQueue);
            }

            /** Removes the element on top of the stack and returns that element. */
            public int Pop()
            {
                if (m_slaveQueue.Any()) return m_slaveQueue.Dequeue();
                if (!m_masterQueue.Any()) return int.MinValue;

                SwapMasterSlave();
                QueueElementMove(m_slaveQueue, m_masterQueue);

                return m_slaveQueue.Dequeue();
            }

            /** Get the top element. */
            public int Top()
            {
                if (m_slaveQueue.Any()) return m_slaveQueue.Peek();
                if (!m_masterQueue.Any()) return int.MinValue;

                SwapMasterSlave();
                QueueElementMove(m_slaveQueue, m_masterQueue);

                return m_slaveQueue.Peek();
            }

            /** Returns whether the stack is empty. */
            public bool Empty()
            {
                return !m_masterQueue.Any() && !m_slaveQueue.Any();
            }
        }

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.Push(x);
 * int param_2 = obj.Pop();
 * int param_3 = obj.Top();
 * bool param_4 = obj.Empty();
 */
```
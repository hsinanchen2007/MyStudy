### 解题思路
1、链表数据分别存储在两个队列中
2、位数是按照 逆序存储的，这样先进先出就可以先计算低位数,有进位保存进位


### 代码

```csharp
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int x) { val = x; }
 * }
 */
        public class Solution
        {
            Queue<int> resultQueue = new Queue<int>();
            public ListNode AddTwoNumbers(ListNode l1, ListNode l2)
            {
                var l1QueueValue = GetQueueValue(l1);
                var l2QueueValue = GetQueueValue(l2);
                var carryValue = 0;
                while (l1QueueValue.Count > 0 || l2QueueValue.Count > 0)
                {
                    var current = (l1QueueValue.Count > 0 ? l1QueueValue.Dequeue() : 0) + (l2QueueValue.Count > 0 ? l2QueueValue.Dequeue() : 0);
                    //判断是否有进位
                    if ((carryValue + current) >= 10)
                    {
                        resultQueue.Enqueue((carryValue + current) % 10);
                        carryValue = 1;
                    }
                    else
                    {
                        resultQueue.Enqueue(carryValue + current);
                        carryValue = 0;
                    }

                }
                //如果最终有进位,需要保存这个进位,例子[5],[5]
                if (carryValue == 1)
                {
                    resultQueue.Enqueue(carryValue);
                }
                ListNode nodeResult = new ListNode(0);
                var preNode = nodeResult;
                SetNode(preNode);
                return nodeResult.next;
            }

            /// <summary>
            /// 解析ListNode存储在队列中
            /// </summary>
            /// <param name="node"></param>
            /// <returns></returns>
            private Queue<int> GetQueueValue(ListNode node)
            {
                Queue<int> queueValue = new Queue<int>();
                while (node.next != null)
                {
                    queueValue.Enqueue(node.val);
                    node = node.next;
                }
                queueValue.Enqueue(node.val);
                return queueValue;
            }

            /// <summary>
            /// 根据队列生成ListNode
            /// </summary>
            /// <param name="preNode"></param>
            private void SetNode(ListNode preNode)
            {
                while (resultQueue.Count > 0)
                {
                    preNode.next = new ListNode(resultQueue.Dequeue());
                    preNode = preNode.next;
                }
            }


        }
```
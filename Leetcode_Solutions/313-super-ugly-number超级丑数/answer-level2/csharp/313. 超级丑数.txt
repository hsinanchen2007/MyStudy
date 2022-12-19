### 解题思路
    使用 n 个队列维护 n 个质因数的丑数（丑数正有序），首先使用每个质因数作为其对应的队列的第一个值。
    往后每次迭代时（注意，迭代次数应少一次，因为第一个丑数是1），获取所有队列的最小值，做为当前的最小丑数，然后通过将此丑数从所在队列移除，然后将此队列及其之后的队列入队当前取到的最小丑数乘以当前队列对应的质因数的值，作为后续的备选丑数（保证了每个队列里的丑数正有序，队列头的丑数总是最小）。
    迭代次数结束后，返回当前的最小质因数即可。

### 代码

```csharp
public class Solution {
    public int NthSuperUglyNumber(int n, int[] primes) {
        if (n == 1) return 1;

        // 初始化每个质因数的队列
        // 第一个丑数是1，其余每个丑数都是最小丑数分别乘以每个质因数
        // 内部运算要全部使用 long，否则会因为指数级增长的数值而导致 int 溢出，从而获取到错误的负数
        Queue<long>[] queues = new Queue<long>[primes.Length];
        for (int index = 0; index < primes.Length; index++)
        {
            queues[index] = new Queue<long>(new[] { (long)primes[index] });
        }

        long minFirstValue = 0;

        // 注意从1开始，因为第"0"个丑数是1
        for (int time = 1; time < n; time++)
        {
            // 获取所有队列里，最前的最小丑数
            // Peek 只取值，不移除
            minFirstValue = long.MaxValue;
            foreach (var queue in queues)
            {
                minFirstValue = Math.Min(minFirstValue, queue.Peek());
            }

            for (int queueIndex = 0; queueIndex < queues.Length; queueIndex++)
            {
                // 通过判断最小丑数来自的队列
                if (minFirstValue == queues[queueIndex].Peek())
                {
                    // 才在对应队列上移除此数
                    queues[queueIndex].Dequeue();

                    // 每个队列只计算自身及更大的队列里的丑数序列，避免出现丑数重复（题目已要求指数列表正有序，也可以自己排序）
                    for (int afterQueueIndex = queueIndex; afterQueueIndex < queues.Length; afterQueueIndex++)
                    {
                        queues[afterQueueIndex].Enqueue(minFirstValue * primes[afterQueueIndex]);
                    }

                    // 找到最小丑数来自的队列后，可以跳出循环，不必继续查找
                    break;
                }
            }
        }

        return (int)minFirstValue;
    }
}
```
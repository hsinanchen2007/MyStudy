### 解题思路

##### 1. 题目概述：将数组分成和相等的 3 个部分

##### 2. 思路：
   - 特征：一定要把数组分成和相等的 3 份,且为完整切分,因此 3 份之和,就应该是全部数组之和,此和是固定的;每份的和也是可以计算出来的,也是固定的;所以只要遍历累计,和为目标值,那么就说明是切分点了;
   - 方案：对整个数组求和,将值除3;遍历数组找到与目标值一致的数组索引位置;
   - 结果：除了数组最后的位置外,还有 2 个位置,那么可切分

##### 3. 知识点：队列

##### 4. 复杂度分析: 
   - 时间复杂度：O(n)  遍历 2 轮数组
   - 空间复杂度：O(1)  


### 代码

```csharp []
public class Solution {
        public bool CanThreePartsEqualSum(int[] A)
        {
            var sum = A.Sum();
            if (sum % 3 != 0) return false;

            var oneValue = sum / 3;
            var queueTemp = new Queue<int>();
            queueTemp.Enqueue(oneValue);
            queueTemp.Enqueue(twoValue);
            queueTemp.Enqueue(threeValue);

            var sumTemp = 0;
            for (var i = 0; i < A.Length; i++)
            {
                if (!queueTemp.Any())
                    break;

                sumTemp += A[i];

                if (queueTemp.Peek() == sumTemp)
                    queueTemp.Dequeue();
            }

            return !queueTemp.Any();
        }
}
```
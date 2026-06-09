### 解题思路
此处撰写解题思路
其实原理并不难，就是拿到对应链表位置的下标，二进制转十进制怎么转大家也都知道。主要就是C#里是没有链表的，我一开始都不知道这该咋写，看数据结构方面的讲解才有个理解。C#太惨淡了都没人写。。。最后要转类型是因为求解N次方的方法是double形，而我们要的是int形，简直脱裤子放屁。

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
public class Solution {
    public int GetDecimalValue(ListNode head) {
            Dictionary<int, int> dic = new Dictionary<int, int>();
            int i = 0;
            while (head != null)
            {
                var aa = head.val;
                var next = head.next;
                dic.Add(i, head.val);
                head = head.next;
                i++;
            }
            double jieguo = 0;
            for (int j = 0; j < dic.Count; j++)
            {
                jieguo += Math.Pow(2, (dic.Count - 1 - j))*dic[j];
            }
            int jieguo1 = 0;
            try
            {
                jieguo1 = Convert.ToInt32(jieguo);
            }
            catch (Exception)
            {

            }
            return jieguo1;
    }
}
```
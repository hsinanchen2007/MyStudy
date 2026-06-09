### 解题思路
这个反转，从尾到头打印链表。其实就是中间带个转换，把链表的值存储到集合中
最后把集合中元素挨个传给数组。

注意的几点：
1. 没有集合的size()函数，那就在遍历链表的时候用一个计数器count=0;count++
2. 链表遍历的通常套路list.add(p.val);
                     p=p.next;
3. 定义ArrayList加泛型，否则会报错。


### 代码

```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public int[] reversePrint(ListNode head) {
        ListNode p=head;  //转换为一个简单的表达式
        ArrayList<Integer> list=new ArrayList();
        int count=0;
        while(p!=null){
            list.add(p.val);
            p=p.next;
            count++;
        }

        int [] arr=new int[count];//如果没法使用size函数，那么用count来计算算了
        
        for(int i=count-1;i>=0;i--){
            arr[count-1-i]=list.get(i); //不加泛型，就会报错Object cannot be 、、/                                        //converted to int
        }
        return arr;
    }
}
```
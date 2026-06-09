
## C#完成该功能
代码如下，几乎每一行都有注释说明
```
C#
```
```
    public static ListNode AddTwoNumbers(ListNode l1, ListNode l2)
            //定义返回值
            var result = new ListNode(-1);
            //定义循环用的对象，将形参制定到temp
            var temp = result;
            //前一轮数字和的十位数
            int Other = 0;
            do
            {
                //取出numbe1和number2的值
                var number1 = l1 == null ? 0 : l1.val;
                var number2 = l2 == null ? 0 : l2.val;
                //计算两数之和 并加上前一轮需要进位的值
                var sum = number1 + number2 + Other;
                //计算个位
                var value = sum % 10 ;
                //计算十位并赋值
                Other = sum / 10;
                //将数据添加到循环链表中
                temp.next = new ListNode(value);
                //循环用的temp对象赋值为循环链表中的下一个对象
                temp = temp.next;
                //l1 l2 指向自己在链表中对应的下一个值
                l1 = l1?.next;
                l2 = l2?.next;
            } while (l1 != null || l2 != null|| Other!=0);
            return result.next;
        }
```
* 核心思路就是do while循环两张链表，将他们每一位的值加起来，如果存在进位的话就将进位存在Other变量中下一次循环使用。在下一次循环时Ohter又会被重置。
* 这里需要注意一下While中的条件 最初是没有写Other!=0这个条件的，直到后面出现了一组测试数据

    [5]

    [5]
  

    结果[0,1].
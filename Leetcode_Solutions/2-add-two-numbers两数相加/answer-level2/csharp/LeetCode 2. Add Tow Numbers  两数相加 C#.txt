
## 解决方案

题目可以理解为2个链表相加，链表依次是 个位、十位、百位、千位 等等，比如链表 (2 -> 4 -> 3) ,表示个位为2，十位为4，百位为3.

### 方法一 : 稳中求胜

首先两个链表的个位相加，若结果大于等于10，则进位值carry赋值为1； 然后两个十位相加，并加上carry值，3值之和作为结果，若结果大于等于10，则carry=1；以此类推。

需要考虑特殊情况：
	
	1. [5] + [5] , 两链表都没有十位，但是carry=1。
	2. [0,1] + [0,1,2] , 两链表长度不一样
	3. [] + [0,1] , 一个链表为空
	4. [0] + [0] , 有些时候这个测试集也会卡住你

C# 代码 :
	
	public ListNode AddTwoNumbers(ListNode l1, ListNode l2)
	        {
	            var resultPre = new ListNode(0);
	            var resultPointer = resultPre;
	            int carry = 0;
	            while (l1 != null && l2 != null)
	            {
	                var sum = l1.val + l2.val + carry;
	                resultPointer.next = new ListNode(sum % 10);
	                carry = sum / 10;
	
	                resultPointer = resultPointer.next;
	                l1 = l1.next;
	                l2 = l2.next;
	            }
	            while (l1 != null)
	            {
	                var sum = l1.val + carry;
	                resultPointer.next = new ListNode(sum % 10);
	                carry = sum / 10;
	
	                resultPointer = resultPointer.next;
	                l1 = l1.next;
	            }
	            while (l2 != null)
	            {
	                var sum = l2.val + carry;
	                resultPointer.next = new ListNode(sum % 10);
	                carry = sum / 10;
	
	                resultPointer = resultPointer.next;
	                l2 = l2.next;
	            }
	            if (carry == 1)
	            {
	                resultPointer.next = new ListNode(1);
	            }
	            return resultPre.next;
	        }

#### 执行结果

执行结果 通过，执行用时 140ms，内存消耗 27.1MB .

#### 复杂度分析

时间复杂度：O(max(m,n))

空间复杂度：O(max(m,n))

### 方法二 : 精简代码

可以看出方法一太罗嗦了，实际上可以进行简化。本质上方法二跟方法一是一个思路的，但是代码看起来整洁了许多，效率上也有轻微的提高。

        public ListNode AddTwoNumbers(ListNode l1, ListNode l2)
        {
            var resultPre = new ListNode(0);
            var resultPointer = resultPre;
            int carry = 0;
            while (l1 != null || l2 != null || carry == 1)
            {
                var sum = carry + (l1 == null ? 0 : l1.val) + (l2 == null ? 0 : l2.val);
                resultPointer.next = new ListNode(sum % 10);
                carry = sum / 10;
                resultPointer = resultPointer.next;
                if (l1 != null) l1 = l1.next;
                if (l2 != null) l2 = l2.next;
            }
            return resultPre.next;
        }

#### 执行结果

执行结果 通过，执行用时 124ms，内存消耗 27.1MB .

#### 复杂度分析

时间复杂度：O(max(m,n))

空间复杂度：O(max(m,n))

## 参考资料汇总

[https://leetcode-cn.com/problems/add-two-numbers/](https://leetcode-cn.com/problems/add-two-numbers/)

[https://leetcode-cn.com/problems/add-two-numbers/solution/liang-shu-xiang-jia-by-leetcode/https://leetcode-cn.com/problems/add-two-numbers/solution/liang-shu-xiang-jia-by-leetcode/]()

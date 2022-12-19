### 解题思路
此处撰写解题思路
**# 1.首先要了解二进制如何转换为十进制：**
    <1>在进行转换时要明白二进制的意义，如果不是unsign型的话，那么二进制的最前面一位代表的是正负，1为负，0为正
    <2>后续的内容就要反向来看，从右至左依次将数字选出，乘上2的次方，第一个就是2的0次方，第二个就是2的1次方，以此类推
    <3>例如：00101  -->  首先看第一位，是0，那么整个转换后的数字将是正数 然后从右至左依次取数字来运算：-->  1 * 2^0 = 1 -->  0 * 2^1 = 0 -->  1 * 2^2 = 4 -->  0 * 2 ^ 4 = 0,最后全部加起来 = 5，然后因为第一位是 0 的缘故所以为+5
**2.正式开始工作**
    <1>阅读题干，本题是一个unsignd型的二进制链表，每一位都被放在链表的一个节点中
    <2>开始解题，本题又两种思路：
        1）首先先将链表反转，然后再顺序遍历链表，进行数值转换
        2）遍历一遍链表，记录下长度，再第二次遍历的时候计算
    <3>本处选择第二种解题思路：
        1）首先遍历完链表，利用 ‘count’ 来记录长度
        2）因为2的次方要从0开始，所以计算值时 while循环的结束条件是 count == -1 时结束
        3）pow(x，y)是一个自定义函数作用是传入两个值, x,y ，计算x的y次方
        4）最后在while循环中完成value值的计算
# 本解题思路仅供个人回忆使用
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
    public int getDecimalValue(ListNode head) {

      ListNode temp = head;
      int value, count;
      
      count = 1;
      value = 0;
      
      while(temp.next != null){
          count ++;
          temp = temp.next;
      }
      
      temp = head;
      count --;

      while(count != -1){
          value = pow(2, count) * temp.val + value;
          temp = temp.next;
          count --;
      }
      
      return value;

	}
	
	public static int pow(int num, int mi) {
		
		int value = 1;
		for(int i = 0; i < mi; i++) {
			value = value * num;
		}
		
		return value;
	}
}
```
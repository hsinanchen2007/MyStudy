![2020040701.PNG](https://pic.leetcode-cn.com/2798866784f30ab27d55650105a0e8e7a2744290bbd8f750e46bfe1f8c3d93be-2020040701.PNG)

### 解题思路
1.首先定义getStep() 方法来计算每个数字对应的权重值

2.声明哈希表map, map中的key为数字的权重, value为链表, 链表的值为权重对应的数字, 在链表中, 数字从小到大排序

3.声明数组count, 用以记录出现的权重值, 相同的权重值只记录一次

4.遍历[lo, hi]范围中的整数, 并将每个数字和数字对应的权重值放入map中

5.插入排序法对count数组中的权重值进行排序 (从小到大排序 )

6.从前往后遍历排序后的数组count中的权重值, 同时对权重值对应的所有数字进行计数, 寻找第k个数, 找到第k个数则退出循环, 返回第k个数字的值


### 代码

```java
class Solution {
	public static int getKth(int lo, int hi, int k) {
        //哈希表, key为数字的权重, value为链表, 链表的值为权重对应的数字, 在链表中, 数字从小到大排序
        Map<Integer,ListNode> map = new HashMap<>();
        //数组count记录出现的权重值, 相同的权重值只记录一次
        int[] count = new int[hi-lo+1];
        int index=0;
        int temp = 0;
        for(int i=lo; i<=hi;i++){
            temp = getStep(i);
            if(!map.containsKey(temp)){
                ListNode node = new ListNode(i);
                map.put(temp,node);
                count[index++]=temp;//记录相应的权重值
            }else{
                ListNode node = new ListNode(i);
                ListNode head = map.get(temp);
                ListNode dummHead = new ListNode(-1);
                dummHead.next = head;
                ListNode cur = dummHead;
                while(cur.next!=null&&cur.next.val<node.val){//按照数字从小到大的顺序, 在合适的位置插入新值
                    cur = cur.next;
                }
                node.next = cur.next;
                cur.next = node;
                map.put(temp,dummHead.next);
            }
        }
        //插入排序法对count数组中的权重值排序, 从小到大
        int j=0;
        for(int i=1;i<index;i++){
            temp = count[i];
            j = i;
            while(j-1>=0&&count[j-1]>temp){
                count[j] = count[j-1];
                j--;
            }
            count[j] = temp;
        }
        //在从前往后遍历数组count中的权重值, 同时对权重值对应的所有数字进行计数, 寻找第k个数, 找到第k个数则退出循环, 返回第k个数的值
        int step = 0;
        STOP:
        for(int i=0;i<index;i++){
            ListNode node = map.get(count[i]);
            while(node!=null){
            	step++;
                temp = node.val;
                node = node.next;
                if(step==k) {
                	break STOP;
                }
            }
        }
        return temp;
    }
    //计算每个数字的权重
    public static int getStep(int num){
        int cnt = 0;
        while(num!=1){
            if(num%2==0){
                num = num/2;
                cnt++;
            }else{
                num = 3*num+1;
                cnt++;
            }
        }
        return cnt;
    }

}
```
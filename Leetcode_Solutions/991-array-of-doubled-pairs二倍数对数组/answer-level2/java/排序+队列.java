![2020011701.PNG](https://pic.leetcode-cn.com/a52098cd3f3d8522783f0b44b8c1a0b048b1d50de4fe58790e6255c659a5670c-2020011701.PNG)
### 解题思路
思路:首先是对数组A进行排序,使数组元素呈升序排列,
声明一个队列记录数组元素的倍数:
--1)数组元素为负数时,队列添加该元素的1/2;
--2)数组元素为非负数时,队列添加该元素的2倍数.
从头遍历数组A,对于遍历到数组A的每一个元素,进行如下操作:
--1)若队列非空,判断该数是否等于队列的首位元素,若等于,则删除队列的首位元素;否则将该元素的倍数添加到队列末尾;
--2)若队列为空,则直接将该元素的倍数添加到队列中.
遍历完数组A后,判断队列是否为空,若队列非空,则返回false;否则,返回true.
(优化:遍历过程中,当遍历到的数组元素不等于队列的首位元素,且该元素大于队列首位元素时,直接返回false)
### 代码

```java
class Solution {
    public boolean canReorderDoubled(int[] A) {
    	Arrays.sort(A);
        Deque<Integer> deque = new LinkedList<>();
        int i=0;
        while(i<A.length) {
        	if(deque.peekFirst()==null) {
        		if(A[i]<0) {
        			deque.addLast(A[i]/2);
        		}else {
        			deque.addLast(A[i]*2);
        		}
        	}else if(deque.peekFirst()!=null){
            	if(deque.peekFirst()==A[i]) {
            		deque.pollFirst();
            	}else{
            		if(deque.peekFirst()>A[i]) {
                		if(A[i]<0) {
                			deque.addLast(A[i]/2);
                		}else {
                			deque.addLast(A[i]*2);
                		}
            		}else {//当数组元素不等于队列的首位元素,且该元素大于队列首位元素时,直接返回false
            			return false;
            		}
            	}
        	}
        	i++;
        }
    	if(deque.peekFirst()!=null) {
    		return false;
    	}
    	return true;
    }
}
```
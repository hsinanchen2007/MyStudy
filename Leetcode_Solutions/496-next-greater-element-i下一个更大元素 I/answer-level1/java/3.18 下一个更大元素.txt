### 解题思路
1.刚开始只想暴力破解
2.单栈+哈希表的方式，利用栈先进后出的特性，再利用哈希表的可以存储键值对的特性。
循环遍历nums2，当遇到后一个数比前一个数大的时候就弹出两个数，并存入哈希表中，然后把后面那个数再push进栈，如果后一个数比前一个数小，则一直push，这样我们就维持了一个单栈结构。
3.再循环遍历nums1，和哈希表中的做对比，找到了就返回哈希表的那个value值，找不到就返回-1

### 代码

```java
class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        //新建栈和哈希表
             Stack<Integer> stack=new Stack<>();
             HashMap<Integer,Integer>map=new HashMap<>();
             int[] res=new int[nums1.length];
             //循环遍历nums2，找到比nums2大的数，存入哈希表中，然后把该数push到栈里面去，方便和下一个数做比较
             for(int i=0;i<nums2.length;i++){
                 while(!stack.empty()&&nums2[i]>stack.peek())
                    map.put(stack.pop(),nums2[i]);
                stack.push(nums2[i]);
             }
             //如果栈不为空，那么加入哈希表的就是该值和-1.
             while(!stack.empty())
             map.put(stack.pop(),-1);
             for(int i=0;i<nums1.length;i++)
             {
                 res[i]=map.get(nums1[i]);
             }
             return res;

    }
}
```
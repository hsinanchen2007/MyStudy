### 解题思路
采用双端队列的方式，头存放最大值（降序），当窗口移动的时候首先需要判断，deque中坐标对应的nums是否还在窗口中，不在removeFirst，在的话，对新添加到窗口中的值和deque中的值进行比较，deque小的话removeLast，如果新进入的窗口小的话，addLast即可，maxnums=deque.getFirst;
时间复杂度为O(n);空间复杂度为O(n)：
### 代码

```java
class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
       //采用双向队列Deque，可以将窗口中最大值储存在队列最左端
        int[] maxNums = new int[nums.length-k+1];
        ArrayDeque<Integer> deque = new ArrayDeque();
        //初始化deque队列
        for(int i=0;i<k;i++){
            cleanDeque(deque,nums,i,k);
        }
        maxNums[0] = nums[deque.getFirst()];
        for(int i =k;i<nums.length;i++){
            cleanDeque(deque,nums,i,k);
            maxNums[i-k+1] = nums[deque.getFirst()];
        }
        return maxNums;
    }
    public void cleanDeque(ArrayDeque<Integer> deque,int[] nums,int j,int k){
        if(!deque.isEmpty()&&deque.getFirst() == (j-k)){
            deque.removeFirst();
        }
        if(deque.isEmpty()){
            deque.addFirst(j);
        }else{
            while(!deque.isEmpty()&&nums[deque.getLast()]<nums[j]){
                deque.removeLast();
            }
            deque.addLast(j);
        }
    }
}
```
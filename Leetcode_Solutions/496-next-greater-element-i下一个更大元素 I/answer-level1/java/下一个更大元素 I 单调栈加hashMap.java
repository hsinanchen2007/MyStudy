### 解题思路
首先计算nums2中每个元素的下一个最大值,使用单调栈从栈顶到尾部从小到大,碰见元素大于栈顶元素,那么通过hashmap记录该元素的下一个大的元素,直到遍历完数组栈内元素对应值都没有最大的,所以map中存储对应是-1
遍历nums2,找到在map中对应的最大元素,代替当前值
### 代码

```java
class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        //key:是nums[i],value是nums[i]的下一个最大值,如果没有就是-1
        Map<Integer,Integer> map=new HashMap<>();
        //单调栈
        Stack<Integer> stack=new Stack<>();
        for(int i=0;i<nums2.length;i++){
           while(!stack.isEmpty()&&nums2[stack.peek()]<nums2[i]){
               //如果nums2[i]大于栈顶元素那么nums2[stack.pop()]的下一个大值就是nums2[i]
               map.put(nums2[stack.pop()],nums2[i]);
           }
            //栈顶元素大于nums[i]入栈
           stack.push(i);
        }
        //剩余的都是找不到下一个最大值直接赋值-1
        while(!stack.isEmpty()){
           map.put(nums2[stack.pop()],-1);
        }
        //通过map中的记录找到对应元素的下一个大的值
        for(int i=0;i<nums1.length;i++){
           nums1[i]=map.get(nums1[i]);
        }
        return nums1; 
    }
}
```
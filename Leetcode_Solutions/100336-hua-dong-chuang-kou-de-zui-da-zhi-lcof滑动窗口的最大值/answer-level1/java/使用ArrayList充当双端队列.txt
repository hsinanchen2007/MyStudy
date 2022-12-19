使用ArrayList充当双端队列

```
class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        if(nums.length==0 || k==0) return new int[0];
        // 两头开的队列
        List<Integer> l = new ArrayList<Integer>(); 
        
        int index=0; // 最大值数组的index
        int[] r = new int[nums.length-k+1];

        for(int i=0; i<nums.length; i++){
            // 应该记录最大值的下标 便于删除超出窗口的元素
            // 这样也可以保证队列里记录的数据有唯一性有序性

            if(l.isEmpty()) l.add(i);

            if(nums[i] >= nums[l.get(0)]) { // 如果新加入的这个值最大
                l.clear();
                l.add(i);
            } 
            else{ // 次大 删除比它小的
                //[foreach递归+remove的写法会报java.util.ConcurrentModificationException]
                // 使用iterator自带的方法 或 将要删除的值更改值
              // 使用iterator自带的方法 或 将要删除的值更改值
                Iterator<Integer> il = l.iterator();
                while(il.hasNext()){
                    if(nums[il.next()] < nums[i]) il.remove();
                }                    

                l.add(i);
            }
            // 删除应该出窗口的值
            Iterator<Integer> il = l.iterator();
            while(il.hasNext()){
                if(il.next()< i-k+1) il.remove();
            }
            if(i>=k-1)  r[index++]=l.get(0);            
        }
        
        for(int i=0; i<r.length; i++) r[i] = nums[r[i]];
        return r;
    }
}
```

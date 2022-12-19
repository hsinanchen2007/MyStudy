方法一：首先看到这道题第一想法就是遍历数组，对于每一个遍历的值按照题目的要求进行查找，这是最笨的方法，最后写出来超时了；
方法二：对于上面的方法一可以进行改进：如果从一个位置开始嵌套查找直到找到一个重复元素，这个过程中所找过的所有元素会形成一个闭环，也就是闭环之外不会有索引指向环内元素，以`[5,4,0,3,1,6,2]`为例，在`5`这个位置按照`值-索引`会形成`0-5,5-6,6-2,2-0`，而nums包含0~N-1，加上索引，每个数都是出现两次，这就是为什么闭环之外不会有索引指向环内元素；
（tips:HashSet比ArrayList有更高的查找效率，时间消耗比是12ms:1125ms）
方法二求解的代码如下：

```
class Solution {
    public int arrayNesting(int[] nums) {
        int result = 0;
        Set<Integer> set = new HashSet<>();
        for(int i=0;i<nums.length;i++){
            int count=0, k=i;
            while(!set.contains(nums[k])){  //出现的重复元素会组成一个闭环
                set.add(nums[k]);
                count++;
                k = nums[k];
            }
            result = Math.max(result,count);
        }
        return result;
    }
}
```
方法三：方法二是用一个HashSet记录走过的位置，其实这个HashSet也是可以省略的，我只要将走过位置的值置为-1就行了，然后遍历到值为-1的位置就知道已经出现重复元素了，方法三的求解代码如下（时间消耗超过100%）：
```
class Solution {
    public int arrayNesting(int[] nums) {
        int result = 0;
        for(int i=0;i<nums.length;i++){
            int count=0, k=i;
            while(nums[k]!=-1){
                count++;
                int tmp = nums[k];
                nums[k] = -1;
                k = tmp;
            }
            result = Math.max(result,count);
        }
        return result;
    }
}
```


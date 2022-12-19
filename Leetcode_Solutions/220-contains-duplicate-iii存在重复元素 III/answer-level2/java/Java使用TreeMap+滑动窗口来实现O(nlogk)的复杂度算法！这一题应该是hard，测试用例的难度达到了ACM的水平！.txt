# 先吐槽一下，__谁出的测试用例！！！__

# 竟然还会有k超出数组长度的情况，还有求和溢出的情况，这都哪跟哪啊！！！这还是考察算法吗！！！

__思路：__
设置一个大小为k的滑动窗口，同时使用一个TreeMap，这个map的键是数组元素，值是该元素最近出现的下标。

设置滑动窗口的意义是使得该窗口中的任意两个元素的下标之差都小于等于k。

而TreeMap则是对于每一个即将进入窗口的元素，我们可以用O(logk)的时间查询到比它稍大和稍小的元素！

然后判断这两个元素(如果存在)和此时的元素插值的绝对值，若小于等于t，则返回true，否则继续处理下一个元素！

why？因为TreeMap是用红黑树实现的，红黑树在查询时可以达到这个复杂度。不仅如此，它在删除元素时也是O(logk)！

为什么不是O(logn)?因为有滑动窗口的限制，使得map中最多只有k个元素！！！（在窗口滑动的时候也要从map中删除元素！！！）

java ac代码：

```
class Solution {
    public boolean containsNearbyAlmostDuplicate(int[] nums, int k, int t) {
                
        if(nums.length <= 1)return false;
        
        TreeMap<Integer,Integer>map = new TreeMap();
        
        for(int i = 0;i <= k && i < nums.length ;i++)
        {
            Map.E***y<Integer,Integer> ceiling = map.ceilingE***y(nums[i]);
            Map.E***y<Integer,Integer> floor = map.floorE***y(nums[i]);
            if(ceiling != null && ceiling.getKey() <= nums[i] + t )
                return true;
            if(floor != null && nums[i] <= floor.getKey() + t)
                return true;
            map.put(nums[i],i);
        }
        
        for(int i = k+1; i < nums.length;i++)
        {
            int loc = map.get(nums[i-k-1]);
            if(loc < i-k)
                map.remove(nums[i-k-1] );
            
            Map.E***y<Integer,Integer> ceiling = map.ceilingE***y(nums[i]);
            Map.E***y<Integer,Integer> floor = map.floorE***y(nums[i]);
            if(ceiling != null && ceiling.getKey() <= nums[i] + t )
                return true;
            if(floor != null && nums[i] <= floor.getKey() + t)
                return true;
            map.put(nums[i],i);
        }
            
        
        return false;
        
    }
}
```


上面的代码虽然是AC的，但是一般来讲是无法理解的，因为测试用例的缘故，封装了太多的细节。

第一个for循环实际上的要把滑动窗口填满，在填充的过程中也在判断是否存在解，由于此时仍在填充窗口，没用必要
去删除元素！所以只有填充逻辑。
对于
```
if(ceiling != null && ceiling.getKey() <= nums[i] + t )
```
这个语句，为什么不是
```
ceiling.getKey() - nums[i] <= t 
```
因为这样可能会溢出！！！(acm级版的测试用例)
为什么不是
```
Math.abs(ceiling.getKey() - nums[i] <= t)
```
因为ceiling求出来就是该元素的 天花板 (大于等于该元素的第一个值)，因此是不需要加绝对值的。
而对于floor也是一样！

还有第一个for循环为什么里面的结束条件有i < nums.length，因为k可能超过数组长度！！！(acm级版的测试用例)

至于第二个for循环，处理开始的删除操作和第一个for循环不一样，其他都一样。

而删除的逻辑是，查看滑动窗口中即将被提出的元素，它最近出现的位置，若最近出现的位置

已经不再窗口中了，那么就把它删除，否则仍然保留在窗口中！

为什么滑动窗口向右滑动了该元素竟然还有可能在窗口中？？？

因为有重复元素啊！！！！









C#自身带有HashSet，而且有一个方法 IntersectWith()	IntersectWith()修改了集，仅包含所传送的集合和集中都有的元素
并且可以CopyTo 直接复制到数组当中
可是数组的长度是固定的，我们怎么可能提前知道有多少交集呢
所以我这里使用了List，然后用ToArray，不过List的背后也是用数组，然后新建数组再拷贝一遍


```
public class Solution {
    
   
    
    public int[] Intersection(int[] nums1, int[] nums2) {
        HashSet<int> one = Insert(nums1);
        HashSet<int> two = Insert(nums2);
        
        int k = one.Count>two.Count?one.Count:two.Count;
        
        List<int> result = new List<int>();
        
        
       foreach(var num in one) {
           if(two.Contains(num)) result.Add(num);
       }
       
        return result.ToArray();
    }
    
    public HashSet<int> Insert(int[] nums){
         HashSet<int> one = new HashSet<int>();
        for(int i=0;i<nums.Length;i++){
            one.Add(nums[i]);
        }
        return one;
    }
        
  
        
}
```

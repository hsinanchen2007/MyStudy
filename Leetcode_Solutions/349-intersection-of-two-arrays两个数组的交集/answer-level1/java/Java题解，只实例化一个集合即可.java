官方题解中是利用两个set进行去重，其实只用一个即可，将nums1数组全部放入set中，再对数组2遍历利用set进行contains。
如果contains为真，说明nums1中也有这个数，直接加入一个arraylist，加入后从set中remove出去，这样就防止对arraylist添加nums2的重复数字了。
```
class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        
        HashSet<Integer> set = new HashSet<>();
        
        for(int num : nums1)
            set.add(num);
        
        ArrayList<Integer> arr = new ArrayList<>();
        
        for(int num : nums2)
        {
            if(set.contains(num))
            {
                arr.add(num);
                set.remove(num);
            }
        }
        
        int[] res = new int[arr.size()];
        
        for(int i = 0; i < arr.size(); i++)
            res[i] = arr.get(i);
        
        return res;
    }
}
```

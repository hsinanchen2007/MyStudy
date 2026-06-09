### 解题思路
两个数组的交集，即较大的数组与较小的那个数组都有的元素
    
找到较小的数组，遍历数组元素，在较大的数组中找是否存在元素即可

存在，就添加进要返回的数组里。添加之前，先确定是否已经添加过。

### 代码

```java
class Solution
{
    public int[] intersection(int[] nums1, int[] nums2)
    {
        if(nums1.length > nums2.length)
        {
            return find(nums2, nums1);
        }
        return find(nums1, nums2);
    }
    
    int[] find(int[] nums1, int[] nums2)
    {
        List<Integer> tmp = new ArrayList<Integer>();
        
        for(int i = 0; i < nums1.length; i++)
        {
            // 添加元素之前，先判断是否已经存在相同元素
            if(contains(nums2, nums1[i]) && !tmp.contains(new Integer(nums1[i])))
            {
                tmp.add(nums1[i]);
            }
        }
        
        int[] res = new int[tmp.size()];
        for(int i = 0; i < res.length; i++)
        {
            res[i] = tmp.get(i);
        }
        return res;
    }
    
    boolean contains(int[] nums, int value)
    {
        boolean contain = false;
        
        for(int i = 0; i < nums.length; i++)
        {
            if(value == nums[i])
            {
                contain = true;
                break;
            }
        }
        
        return contain;
    }
}
```
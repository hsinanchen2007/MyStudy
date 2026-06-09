### 解题思路
将两个数字转化为两个集合HashSet<Integer>，遍历较小的那个集合的所有元素，对于每个元素，如果另一个集合也含有该元素，则该元素是交集中的元素。最后用数组返回所有交集中的元素即可。返回时要注意一开始创建数组是数组的大小可能大于交集元素的个数，则最后该数组中会有多余的0，要记得去掉。
时间复杂度：O(n+m)。n、m分别为两个数组的大小。
空间复杂度：O(n+m)。最坏的情况是两个数组的元素均不相同。

### 代码

```java
class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        HashSet<Integer> set1=new HashSet<Integer>();
        for(int i : nums1)
            set1.add(i);
        HashSet<Integer> set2=new HashSet<Integer>();
        for(int i : nums2)
            set2.add(i);
        if(set1.size()<set2.size())
            return getIntersection(set1,set2);
        else
            return getIntersection(set2,set1);
    }
    public int[] getIntersection(HashSet<Integer> a,HashSet<Integer> b) {
        int[] c=new int[a.size()];
        int idx=0;
        for(Integer i : a)
            if(b.contains(i))
                c[idx++]=i;
        int[] output=new int[idx];
        for(int i=0;i<idx;i++)
            output[i]=c[i];
        return output;
    }
}
```
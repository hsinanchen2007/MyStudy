将第一个数组转换成集合,创建一个新数组长度为集合的长度,for 循环遍历第二个数组如果集合中有该数,将该数加入新创建的数组.remove集合中的该数,这里有个坑remove有两个方法一个是移除下标一个是移除对象,所以要将移除的数转成对象,int转成Integer.

```
class Solution {
    public int[] intersect(int[] nums1, int[] nums2) {
        List<Integer> list1 = new ArrayList<>();
        for (int a : nums1) {
            list1.add(a);
        }
        int a[] = new int[list1.size()];
        int temp = -1;
        for (int i = 0; i < nums2.length; i++) {
            if (list1.contains(nums2[i])) {
                temp++;
                a[temp] = nums2[i];
                Integer x = nums2[i];
                list1.remove(x);
            }
        }
        return Arrays.copyOf(a, temp + 1);
    }
}
```
时间复杂度:O(n)  
空间复杂度:O(n)
### 解题思路
和Intersection of Two Arrays I 一样用了排序然后用两个指针一起从零开始，遇到一样的就加入output的list，然后两个一起加一；遇到不一样的，小的那个加一。比上一题更加简单的是都不用在output list 里查重了。挺快的，不过这么做好像空间复杂度挺高的（可能因为有一个动态list和一个最后返回的数组？），内存消耗很高。

### 代码

```java
class Solution {
    public int[] intersect(int[] nums1, int[] nums2) {
        ArrayList<Integer> list = new ArrayList<Integer>();
        Arrays.sort(nums1);
        Arrays.sort(nums2);
        int index1 = 0,index2=0;
        while(index1 < nums1.length && index2 < nums2.length) {
            if(nums1[index1] == nums2[index2]) {
                list.add(nums1[index1]);
                index1 ++;
                index2 ++;
            }else if(nums1[index1] < nums2[index2]) {
                index1 ++;
            }else {
                index2 ++;
            }
        }
        int[] output = new int[list.size()];
        for(int i =0;i < output.length;i++) {
            output[i] = list.get(i);
        }
        return output;
    }
}
```
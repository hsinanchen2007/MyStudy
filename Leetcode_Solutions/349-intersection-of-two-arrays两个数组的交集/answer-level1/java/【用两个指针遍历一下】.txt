### 解题思路
做这道题的时候是在sort排序的category下面，所以想用sort，所以就把两个nums数组给排序了。排序了以后用两个index指针一起从头开始遍历，发现一样的就一起加一，把一样的数字加进最后output的数组里；不一样就把小的那个index指针加一。遍历一遍就能出结果了。我感觉这是一个O(n+m)的方法如果不算sort的时间还有查output的list有没有重复的时间。小白感觉还挺快的嘿嘿。

### 代码

```java
class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        ArrayList<Integer> list = new ArrayList<Integer>();
        Arrays.sort(nums1);
        Arrays.sort(nums2);
        int index1 = 0,index2=0;
        while(index1 < nums1.length && index2 < nums2.length) {
            if(nums1[index1] == nums2[index2]) {
                if(!list.contains(nums1[index1])) list.add(nums1[index1]);
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
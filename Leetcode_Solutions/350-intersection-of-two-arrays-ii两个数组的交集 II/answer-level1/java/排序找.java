### 解题思路
直接看代码吧 思路清晰 

### 代码

```java
class Solution {
    public int[] intersect(int[] nums1, int[] nums2) {
        ArrayList<Integer> list = new ArrayList();

        if (nums1.length == 0 || nums2.length == 0) {
            return new int[0];
        }

        //排序
        Arrays.sort(nums1);
        Arrays.sort(nums2);
    
        int i = 0;
        int j = 0;
        //循环数组
        while (i < nums1.length && j < nums2.length) {
            if (nums1[i] > nums2[j]) {
                j++;
            } else if (nums1[i] < nums2[j]) {
                i++;
            } else {//找到了 相等
                list.add(nums1[i]);
                i++;
                j++;
            }
        }

        int[]  arr = new int[list.size()];
        int k = 0;
        for (Integer num : list) {
            arr[k++] = num;
        }
        
        return arr;
    }
}
```
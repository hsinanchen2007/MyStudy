### 解题思路
1）遍历num1，依次比较num1中哪些数据出现在了num2中，
2）因为要求元素出现在两个数组中的次数要一致，因此需要将出现过的数据做删除
### 代码

```java
class Solution {
 public static int[] intersect(int[] nums1, int[] nums2) {
        if (nums1.length ==0 || nums2.length==0){
            return new int[0];
        }
        List<Integer> resultList = new ArrayList<>();
        List<Integer> nums2List = new ArrayList<>();
        for (int i=0;i<nums2.length;i++){
            nums2List.add(nums2[i]);
        }

        for (int i=0;i<nums1.length;i++){
            int j =0;
            while (j<nums2List.size() && nums1[i] != nums2List.get(j)){
                j++;
            }
            if(j>=nums2List.size()){
                continue;
            }
            resultList.add(nums1[i]);
            nums2List.remove(Integer.valueOf(nums1[i]));
        }
        int []resultArray = new int[resultList.size()];
        for (int i=0;i<resultList.size();i++){
            resultArray[i] = resultList.get(i);
        }
        return resultArray;
    }

时间复杂度：O(n^2)
空间复杂度：O(n)

}
```
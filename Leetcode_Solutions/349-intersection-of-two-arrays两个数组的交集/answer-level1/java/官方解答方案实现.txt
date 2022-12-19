### 解题思路
1)利用java.set集合的contains方法判断集合是否包含某个元素
### 代码

```java
class Solution {
public int[] intersection(int[] nums1, int[] nums2) {
        if (nums1.length == 0 || nums2.length == 0) {
            return new int[0];
        }
        Set set = new HashSet<>();
        List<Integer> resultList  = new ArrayList<>();
        for (int i=0;i<nums1.length;i++){
            set.add(nums1[i]);
        }
        for (int k=0;k<nums2.length;k++){
            if (set.contains(nums2[k])) {
                set.remove(nums2[k]);
                resultList.add(nums2[k]);
            }
        }

        int[] resArray = new int[resultList.size()];
        for (int i = 0; i<resultList.size(); i++){
            resArray[i] = resultList.get(i);
        }
        return resArray;

    }


}
时间复杂度：O(n)
空间复杂度：O(n)
```
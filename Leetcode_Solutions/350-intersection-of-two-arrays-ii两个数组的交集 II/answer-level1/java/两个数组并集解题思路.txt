### 解题思路
- 数组先排序: O(n log(n))
- 使用while循环仅仅向后遍历2个数组，for循环没法控制起始点
- 使用其中一个数组作为结果集数组——因为其遍历后，前面的数据没用了，可以拿来用
- 匹配到则把该值记录到结果集数组中
- 最后截取结果集合数组中实际的匹配元素

### 代码

```java
public class Solution {

    /**
     * 先排序再比较
     * @param nums1
     * @param nums2
     * @return
     */
    public int[] intersect(int[] nums1, int[] nums2){
        // 排序
        Arrays.sort(nums1);
        Arrays.sort(nums2);

        int i=0; // 控制nums1
        int j=0; // 控制nums2
        int k=0; // 控制结果集数组

        while( i<nums1.length && j< nums2.length ){
            // 比较
            if( nums1[i] > nums2[j] ){
                // 大于则nums2往后走
                j++;
            }else if(nums1[i] < nums2[j]){
                // 小于则nums1往后走
                i++;
            }else{
                // 匹配到则记录； 且nums1、nums2都往后走
                nums1[k++] = nums1[i];
                i++;
                j++;
            }
        }

        return Arrays.copyOf(nums1, k);

    }

}
```
### 解题思路
本题是典型的 使用`Set`查找存放**非重复元素**的容器

- 定义一个记录`nums2`中的元素种类的`record`的`Set`

- 再定义一个确立最终元素的`result`的`Set`，通过比较`nums1`和`nums2`，将**相同种类的元素**放入到`result`中

- 最后定义一个**接收结果**的`ans`数组，通过遍历`result`中已经确立的元素种类依次放入`ans`数组即可。

### 代码

```java []
class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        
        // 如果数据量大，应当考虑 TreeSet
        // 定义一个 record 的 Set，将 nums2 中元素的种类放入其中（不能有重复的）
        HashSet<Integer> record = new HashSet<>();        
        for (int i = 0; i < nums2.length; i++) {
            record.add(nums2[i]);
        }
        
        // 在 nums1 中判断是否包含 nums2 中的元素，有则添加至 result 的 Set 中
        HashSet<Integer> result = new HashSet<>();
        for (int i = 0; i < nums1.length; i++) {
            if ( record.contains(nums1[i]) ) {
                result.add(nums1[i]);
            }
        }
        
        // 定义一个存放 result 中确立下来的元素种类的 ans 数组
        int[] ans = new int[result.size()];
        int index = 0;        
        for (int num : result) {
            // 将 result 中依次遍历到的元素种类放入到 ans 数组中
            ans[index] = num;
            index++;
        }
        return ans;
    }
}
```
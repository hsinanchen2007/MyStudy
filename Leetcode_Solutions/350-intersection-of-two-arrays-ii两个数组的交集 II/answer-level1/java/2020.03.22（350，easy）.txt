### 解题思路
本题和`349`题换汤不换药，上一题的要求需要用`Set`来存放元素，而本题则是用的`Map`

- 思路其实和`349`基本一致，**区别**就是需要用`Map`既存放元素本身，还要存放其个数值（**重复元素也要计算在内**）

- 剩下的就是一样的了，具体细节参考`349`题解题思路或者本题代码注释（很详细了）

### 代码

```java []
class Solution {
    public int[] intersect(int[] nums1, int[] nums2) {
        
        // 定义一个记录 nums2 中元素个数的 result Set
        HashMap<Integer,Integer> record = new HashMap<>();
        // 遍历 nums2 元素个数
        for (int num : nums2) {
            
            // 如果 record 中还没有存放当前所指的 num 
            if ( !record.containsKey(num) ) {
                // 则将 num 放入 record，且对应的值赋为 1
                record.put(num, 1);
            // 如果 record 中已经存放了当前所指的 num
            } else {
                // 就将 record 中当前 num 所对应的值 +1
                record.put(num, record.get(num) + 1);
            }
        }
        
        // 这里直接定义一个 result List 存放与 nums2 对应的元素
        List<Integer> result = new ArrayList<>();
        for (int num : nums1) {
            // 如果当前所指的元素 num 在 record 中存在，且值不为 0
            if (record.containsKey(num) && record.get(num) > 0) {
                // 就将该元素放入 result List 中
                result.add(num);
                // 同时 record 里该元素的值 -1
                record.put(num, record.get(num) - 1);
            }
        }
        
        // 以下同上一题步骤
        int[] ans = new int[result.size()];
        int index = 0;
        for (int num : result) {
            ans[index] = num;
            index++;
        }
        return ans;
    }
}
```
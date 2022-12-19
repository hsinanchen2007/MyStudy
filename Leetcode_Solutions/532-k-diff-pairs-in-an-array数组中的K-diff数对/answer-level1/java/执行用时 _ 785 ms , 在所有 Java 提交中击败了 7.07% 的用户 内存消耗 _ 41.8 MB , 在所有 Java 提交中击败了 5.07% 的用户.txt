### 解题思路
一遍出结果，本题首先对题进行排序，随后判断二者之差绝对值是否为目标值，如果是则使用map集合进行储存，这里利用map集合键值不可以重复的特点，并出现键值重复时会自动更新值和键的原理，随后遍历map的键值，遍历完毕有多少键值就有多少个数。

### 代码

```java
class Solution {
    public int findPairs(int[] nums, int k) {
        int count = 0;
        Map<Integer,Integer> map = new HashMap<Integer,Integer>();
        Arrays.sort(nums);
        for(int i = 0;i<nums.length-1;i++) {
            for(int j = i+1;j<nums.length;j++) {
                if(Math.abs(nums[i]-nums[j])==k) {
                    map.put(nums[i],nums[j]);
                }
            }
        }
        for(Integer key:map.keySet()) {
            count++;
        }
        return count;
    }
}
```
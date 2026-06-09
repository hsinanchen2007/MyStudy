### 解题思路
之前用HashMap遍历两次，思考了一下可以优化，一次遍历就可以解出来。
遍历数组，这里有个技巧是判断哈希表中是否存在当前元素对应的target-nums[i]，存在就直接返回当前元素的下标以及哈希表Value中存储的下标即可，并且一次遍历也能避免使用同一个下标的元素。
题目的意思实际是不能用同一个下标的元素求和得到target，但可以用不同下标的相同大小的元素求和得到target

执行用时 :2 ms, 在所有 Java 提交中击败了99.57%的用户  
内存消耗 :42.1 MB, 在所有 Java 提交中击败了5.02%的用户

### 代码

```java
class Solution {
    public int[] twoSum(int[] nums, int target) {
        int[] arr = new int[2];
        HashMap<Integer,Integer>hs = new HashMap<>();
        for(int i = 0;i<nums.length;i++){
            if(!hs.containsKey(target-nums[i])){
                hs.put(nums[i],i);
            }
            else{
                arr[0] = hs.get(target-nums[i]);
                arr[1] = i;
                break;
            }
        }
        return arr;
    }
}
```
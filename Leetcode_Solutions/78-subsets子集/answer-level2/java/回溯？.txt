### 解题思路
此处撰写解题思路
执行用时 :
2 ms
, 在所有 Java 提交中击败了
31.34%
的用户
内存消耗 :
39.6 MB
, 在所有 Java 提交中击败了
5.28%
的用户
### 代码

```java
class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        res.add(new ArrayList<>());
        for (int i = 0; i < nums.length; i++){
            int size = res.size();
            for (int j = 0; j < size; j++){
                List<Integer> tmp = new ArrayList<>(res.get(j));
                tmp.add(nums[i]);
                res.add(tmp);
            }
        }
        return res;
    }
}
```
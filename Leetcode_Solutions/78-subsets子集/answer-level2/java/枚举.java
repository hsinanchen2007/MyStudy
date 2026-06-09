### 解题思路
通过观察可以发现，每新增一个数字的幂集就是前一个幂集的所有元素加上这个数字再加上原有的幂集

### 代码

```java
class Solution {

    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        List<Integer> t = new ArrayList<>();
        t.add(nums[0]);
        res.add(t);
        for (int i = 1; i < nums.length; i++) {
            List<Integer> temp = new ArrayList<>();
            List<List<Integer>> temp2 = new ArrayList<>();
            temp.add(nums[i]);
            temp2.add(temp);
            for (List l : res) {
                List<Integer> temp1 = new ArrayList<>(l);
                temp1.add(nums[i]);
                temp2.add(temp1);
            }
            for (List l : temp2) {
                res.add(l);
            }
        }
        res.add(new ArrayList<Integer>());
        return res;
    }
}
```
### 解题思路
用一个数组存储从1到n每个数字是否出现，出现为1，未出现为0。
将未出现的数字保存到List集合。

### 代码

```java
class Solution {
    public List<Integer> findDisappearedNumbers(int[] nums) {
        List res = new ArrayList();
        if(nums.length == 0)
            return res;
        int max = nums.length;
        int[] p = new int[max+1];
        for(int i=1;i<max+1;i++)
            p[i] = 0;
        for(int i=0;i<nums.length;i++){
            p[nums[i]] = 1;
        }
        for(int i=1;i<=max;i++){
            if(p[i] != 1)
                res.add(i);
        }
        return res;
    }
}
```
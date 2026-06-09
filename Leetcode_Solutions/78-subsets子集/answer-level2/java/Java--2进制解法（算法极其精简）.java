### 解题思路
每个数组，都有2的n次方的情况
如[1,2,3]解和其**2进制**表示如下：
* []----------000
* [1]---------100
* [2]---------010
* [3]---------001
* [1,2]-------110
* [1,3]-------101
* [2,3]-------011
* [1,2,3]-----111

### 代码

```java
class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        int n = nums.length;
        //每个都有2的n次方个子集
        double count = Math.pow(2, n);
        for (int i = 0; i < count; i++) {
            List<Integer> s = new ArrayList<>();
            for (int j = 0; j < n; j++) {
                if ((i>>j&1)==1){
                    s.add(nums[j]);
                }
            }
            res.add(s);
        }
        return res;
    }
}
```
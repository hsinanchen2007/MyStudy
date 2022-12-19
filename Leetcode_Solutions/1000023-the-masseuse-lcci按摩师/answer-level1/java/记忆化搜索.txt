### 解题思路
![QQ截图20200324184723.jpg](https://pic.leetcode-cn.com/a5a5e39f0a1f9a6ecae9c2052cc720d785ffb654b932c170ee682228af8aef2c-QQ%E6%88%AA%E5%9B%BE20200324184723.jpg)
此处撰写解题思路

### 代码

```java
class Solution {
    int[] memo ;

    public int massage(int[] nums) {
        memo = new int[nums.length];
        for (int i = 0; i < memo.length; i++) {
            memo[i] = -1;
        }
        return tryPretime(nums, 0);
    }

    public int tryPretime(int[] nums, int index) {
        if (index >= nums.length)
            return 0;
        int res = 0;
        if(memo[index]!=-1)
            return  memo[index];
        for (int i = index; i < nums.length; i++) {
            res = Math.max(res, nums[i] + tryPretime(nums,i+2));
        }
        memo[index] = res;
        return res;
    }
}
```
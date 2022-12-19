### 解题思路
1. 递归发糖

### 代码

```java
class Solution {
    public int[] distributeCandies(int candies, int num_people) {
        // 入参的边界题目已经给出
        int[] res = new int[num_people];
        // 给第0个发1颗，此时还剩candies颗
        helper(res, 0, 1, candies);
        return res;
    }
    // 给第i个人发num个糖果，此时还剩left个糖果
    private void helper(int[] res, int ith, int num, int left) {
        ith = ith % res.length;    
        // 不够分页全部分给他
        if (left <= num) {
            res[ith] += left;
            return;
        }
        res[ith] += num;
        // 递归的时候，给第i+1个人分num+1个糖果，此时还剩left-num个，因为给第i个分了num个
        helper(res, ith + 1, num + 1, left - num);
    }
}
```
### 解题思路
这题咋看起来很复杂，好像是有限空间搜索的问题，但是由于所以数都是正整数，结果就只有一种可能了，就是
A/(B/C/D/...).

### 代码

```java
class Solution {
    public String optimalDivision(int[] nums) {

        StringBuilder sb = new StringBuilder();
        sb.append(nums[0]);
        if (nums.length == 1) return sb.toString();
        sb.append('/');
        if (nums.length == 2) {
            sb.append(nums[1]);
            return sb.toString();
        }
        sb.append('(');
        for (int i = 1; i < nums.length; i++) {
            sb.append(nums[i]);
            sb.append('/');
        }
        sb.deleteCharAt(sb.length() - 1);
        sb.append(')');

        return sb.toString();
    }
}
```
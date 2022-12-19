解题思路：
1.根据ascii码，我们将astr.charAt(i)减去'a',这样能获取计数数组cnt的索引。依次统计出现次数。
2.根据题目要求：不能有重复，得到返回结果。

```
class Solution {
    public boolean isUnique(String astr) {
        boolean res = true;
        int[] cnt = new int[53];
        for (int i = 0; i < astr.length(); i++){
            cnt[astr.charAt(i) - 'a']++;
        }
        for (int n : cnt) {
            if (n > 1) {
                res = false;
                break;
            }
        }
        return res;
    }
}
```

### 解题思路
此处撰写解题思路
没什么说的。。
执行用时 :
3 ms
, 在所有 Java 提交中击败了
49.94%
的用户
内存消耗 :
49 MB
, 在所有 Java 提交中击败了
100.00%
的用户
### 代码

```java
class Solution {
    public int[] exchange(int[] nums) {
            int len = nums.length;
            int tot = 0;
            int res[] = new int[len];
            for (int num : nums){
                if (num % 2 == 1){
                    res[tot] = num;
                    tot++;
                }
            }
           for (int num : nums){
                if (num % 2 == 0){
                    res[tot] = num;
                    tot++;
                }
            }            
            return res;
    }
}
```
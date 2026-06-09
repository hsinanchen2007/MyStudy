执行用时 :5 ms, 在所有 Java 提交中击败了98.70%的用户
内存消耗 :46.7 MB, 在所有 Java 提交中击败了93.49%的用户

### 解题思路
用一个数组计数

### 代码

```java
class Solution {
    public List<Integer> findDisappearedNumbers(int[] nums) {
        int[] counter = new int[nums.length];
        for (int i = 0; i < nums.length; i++) {
            counter[nums[i]-1]++;
        }
        List<Integer> answer = new ArrayList<>();
        for (int i = 0; i < counter.length; i++) {
            if (counter[i] == 0) {
                answer.add(i+1);
            }
        }
        return answer;
    }
}
```
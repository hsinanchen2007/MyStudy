### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int validSubarrays(int[] nums) {
        Stack<Integer> st = new Stack<>();
        int sum = 0;
        for (int i = 0; i < nums.length; i++) {
            while (st.size() > 0 && nums[st.peek()] > nums[i]) {
                sum += i - st.pop();
            }
            st.push(i);
        }
        while (st.size() > 0) {
            sum += (nums.length - st.pop());
        }
        return sum;
    }

}
```
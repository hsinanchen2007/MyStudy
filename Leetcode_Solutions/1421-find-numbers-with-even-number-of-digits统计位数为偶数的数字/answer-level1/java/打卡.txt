### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int findNumbers(int[] nums) {
        int count = 0;
        for(int i : nums) {
            if(String.valueOf(i).length()%2 == 0) count++;
        }
        return count;
    }
}
```
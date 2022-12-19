### 解题思路
    暴力法(输入数组过长会超出时间限制)
### 代码

```java
class Solution {
    public int majorityElement(int[] nums) {
        int answer = 0;
       
        for(int i : nums) {
            answer = i;
            int counter = 0;
            for(int j : nums) {
                if(answer == j) {
                    counter++;
                    if(counter > nums.length / 2) {
                        return answer;
                    }
                }
            }
        }
        return -1;
    }
}
```
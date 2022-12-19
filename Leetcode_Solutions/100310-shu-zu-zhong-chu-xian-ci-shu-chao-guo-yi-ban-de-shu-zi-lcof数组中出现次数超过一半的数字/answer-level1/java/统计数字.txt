### 解题思路
此处撰写解题思路
采用投票法，初始计数为0，数字相同+1，不同-1，数字超过一半的时显然计数大于0；为了保存这个数字，我们可以把这个当作条件，只有当计数等于0的时候才改变这个临时变量temp，如果不等于0，说明这个数字出现的次数超过之前数字。
### 代码

```java
class Solution {
    public int majorityElement(int[] nums) {
        int count = 0, temp = 0;
        for(int num : nums){
            if(count == 0)
                temp = num;
            count += (temp == num) ? 1 : -1;
        }
        return temp;
    }
}
```
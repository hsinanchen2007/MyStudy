### 解题思路
考虑打劫[i...len-1]最高金额问题，
- 初始状态
```java
money[len-1]=nums[len-1];
```

- 转移方程：
```java 
money[i]=Math.max(nums[i]+(i+2>=len?0:money[i+2]),money[i+1]);
```

### 代码

```java
class Solution {
    public int rob(int[] nums) {
        if(nums.length==0){
            return 0;
        }
        int len = nums.length;

        int money[]=new int[len];
        money[len-1]=nums[len-1];
        for(int i=len-2;i>=0;i--){
            money[i]=Math.max(nums[i]+(i+2>=len?0:money[i+2]),money[i+1]);
        }
        return money[0];

    }
}
```
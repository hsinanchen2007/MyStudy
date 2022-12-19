### 解题思路
使用Mathlog10()方法得到位数要比num/10要快

### 代码

```java
class Solution {
    public int findNumbers(int[] nums) {
        int result = 0;
        for (int i = 0; i < nums.length; i++){
            // if (isEven(nums[i])){
            //     result++;
            // }
            if ((int)(Math.log10(nums[i]) + 1) % 2 == 0){
                result++;
            }
        }
        return result;
    }

    public boolean isEven(int num){
        int digits = 1;
        while (num / 10 >= 1){
            digits += 1;
            num = num / 10;
        }
        if (digits % 2 == 0){
            return true;
        }else{
            return false;
        }
    }
}
```
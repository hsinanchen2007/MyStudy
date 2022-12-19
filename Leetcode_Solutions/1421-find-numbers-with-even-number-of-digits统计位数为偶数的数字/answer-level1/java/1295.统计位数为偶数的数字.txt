### 解题思路
对每一个整数元素进行判断

### 代码

```java
class Solution {
    public int findNumbers(int[] nums) {
        int sum=0;
        for(int i=0;i<nums.length;i++){
            int n=0;
            int s=0;
            n=nums[i];
            while(n!=0){

                s++;
                n=n/10;
            }
            if(s%2==0) sum++;
        }
        return sum;
    }
}
```
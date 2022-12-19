### 解题思路
思路很简单，暴力求解，两层循环。外层循环作为nums[i]去和内层循环遍历出的nums所有元素比较，有比它小的就让计数变量temp++，遍历一次后将值赋给新建数组的i位置，在内层循环开始时将temp初始化为0。小白只想到了这种方法哈哈

### 代码

```java
class Solution {
    public int[] smallerNumbersThanCurrent(int[] nums) {
        int[] arr = new int[nums.length];
        for(int i = 0;i< nums.length;i++){
            int temp = 0;
            for(int j = 0;j< nums.length;j++){
                if(j!=i&&nums[j]<nums[i]){
                    temp++;
                }
            }
            arr[i] = temp;
        }
        return arr;
    }
}
```
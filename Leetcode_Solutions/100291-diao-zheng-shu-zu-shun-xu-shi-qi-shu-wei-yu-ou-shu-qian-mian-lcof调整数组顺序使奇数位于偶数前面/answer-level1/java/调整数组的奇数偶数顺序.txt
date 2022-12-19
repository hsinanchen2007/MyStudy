### 解题思路
不需要考虑原始顺序的话，采用首尾双指针即可；
如果需要保持原有顺序，只需要分别采用两个数组，去存储对应的奇数和偶数；

### 代码

```java
class Solution {
    public int[] exchange(int[] nums) {
        int[] array = new int[nums.length];
        int left = 0,right=nums.length-1;
        for(int num:nums){
            if(num%2==1){
                array[left++] = num;
            }else{
                array[right--] = num;
            }
        }
        return array;
    }
}
```
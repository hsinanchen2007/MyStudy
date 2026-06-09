### 解题思路
方法二：
我最开始的思路是（见方法二），用双指针start 和 end两头跑，当start遇到0，就跟end置换位置。
然后对其它元素进行挪动，但执行用时7ms。

方法一：
后来改用for循环和单指针index，index初始为0
当for循环遇到非0的元素，就放在对应的index位置上，同时index + 1
一轮循环后，非0的元素都在前index位置。

然后在用for循环将index之后的元素置换为0，或者，在第一个for循环的时候，同时把nums[i]改为0，记得条件是index与i不重叠的时候。

### 代码
方法一：
```java
class Solution {
    public void moveZeroes(int[] nums){

        int len = nums.length;

        int index = 0;
        for(int i = 0; i < len; i++){
            if(nums[i] != 0){
                nums[index] = nums[i];
                if(index != i) nums[i] = 0;
                index++;
            }
        }

        // for(int i = index; i < len; i++){
        //     nums[i] = 0;
        // }
    }
}
```
方法二：
```java
class Solution {
    public void moveZeroes(int[] nums) {
        int len = nums.length;

        int start = 0, end = len -1;
        while(start < end){
            if(nums[start] == 0){
                for(int i = start; i < end; i++){
                    nums[i] = nums[i+1];
                }
                nums[end] = 0;
                end--;
            }else{
                start++;
            }
        }
    }
}
```
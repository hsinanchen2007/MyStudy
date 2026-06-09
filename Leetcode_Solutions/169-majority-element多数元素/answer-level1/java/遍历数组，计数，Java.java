### 解题思路
解题思想:在已知数组存在多数元素的情况下，若多数元素的值为result，计数为count
        其余元素的计数为count1，count2,...,countn
        多数元素是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素
        所以count-（count1+count2+...+countn）>0

过程：
遍历数组，设定返回值result和对应的计数器count。
若nums[i]与result相等，则count++；
若nums[i]与result不相等，若count==0，则将result换成nums[i],且count++
                        若count>0 ,则count--，result不变
由于给定一个大小为 n 的数组，找到多数元素。多数元素是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素。
遍历到数组最后，一定存在着一个数result，对应的count大于0。
   
代码假定：数组为空，一定存在着多数元素。 

时间复杂度:O（N）遍历一遍数组的时间。
空间复杂度:O（1）仅需要记录result，和计数器count的空间。                    


### 代码

```java
class Solution {
    public int majorityElement(int[] nums) {
        int count = 1;
        int result = nums[0];
        for(int i=1;i<nums.length;i++){
            if(nums[i] == result){
                count++;
            }else{
                if(count == 0){
                    result = nums[i];
                    count++;
                }else{
                    count -- ;
                }
            }
        }
        return result;

    }
}
```
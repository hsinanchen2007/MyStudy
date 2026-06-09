### 解题思路
本来想用for循环，但是运行不出来，这个有点像二分查找，我也不知道是不是...

### 代码

```java
class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int index1=0;
        int index2=numbers.length-1;//一个从头开始，一个从尾开始
               while(index1<index2){
                int nums=numbers[index1]+numbers[index2];
                if(nums==target){
                    return new int []{index1+1,index2+1};
                }else if(nums>target){
                    index2--;
                }else if(nums<target){
                    index1++;
                }
            }
return null;
     }
}
```
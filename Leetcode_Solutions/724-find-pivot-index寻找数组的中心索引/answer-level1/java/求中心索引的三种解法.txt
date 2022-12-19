### 方法一
思路：索引从左往右遍历，同时每遍历一个，利用双指针在索引的左边和右边同时向索引逼近，并求得两边的和，进行比较，如果相等，返回当前索引，如果不相等，则继续循环。若索引遍历完毕都没有索引左边和右边的值相等，则该数组不存在中心索引，即返回-1.
```java
class Solution {
    public int pivotIndex(int[] nums) {
        if(nums==null||nums.length==1)
            return -1;
        int index;
        for(index=0;index<nums.length;index++){
            int start=0;
            int end= nums.length-1;
            int sum1 = Sum1(0,index,nums);
            int sum2 = Sum2(index,end,nums);
            if(sum1==sum2){
                return index;
            }
        }
        return -1;
        
    }
    
    public static int Sum1(int start,int index,int[] nums){
        int sum = 0;
        for(int i = start;i<index;i++){
            sum+=nums[i];
        }
        return sum ;
    }
    
    public static int Sum2(int index,int end,int[] nums){
        int sum = 0;
        for(int i = end;i>index;i--){
            sum+=nums[i];
        }
        return sum ;
    }
        
}
```
该方法时间复杂度是：O（N^2），耗时：377ms
空间复杂度是：O（1）

### 方法二 先计算总和
```java

class Solution {
    public int pivotIndex(int[] nums) {
        if(nums==null||nums.length==1)
            return -1;
        int sum =0;
        for(int index=0;index<nums.length;index++){
            sum+=nums[index];
        }
        int leftNum =0;
        for(int index=0;index<nums.length;index++){
            if(index!=0){
                 leftNum += nums[index-1];
            }
            int rightNum = sum-leftNum-nums[index];
            if(leftNum == rightNum){
                return index;
            }
        }
        return -1;
    }
}
```
时间复杂度：O（N^2）,空间复杂度：0（1），耗时：7ms,内存：

### 方法三 利用空间换时间
思路：一共遍历两边，创建两个数组，用于保存索引每向右移动一下，索引两边数字之和。第二遍同时遍历两个数组，若存在同下标下值相等，则返回该下标，即中心索引。

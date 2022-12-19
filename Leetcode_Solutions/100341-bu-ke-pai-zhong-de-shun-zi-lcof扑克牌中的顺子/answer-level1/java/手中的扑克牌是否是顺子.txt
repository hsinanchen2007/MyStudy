### 解题思路
首先对手中的扑克牌采用排序算法进行排序，大小王按照0来处理；
设定一个count,遇到大小王就+1；
如果遇到两张牌相等，直接false,说明不存在顺子牌；
再用count去补对应顺子缺少的个数；
### 代码

```java
class Solution {
    public boolean isStraight(int[] nums) {
        if(nums.length<5){
            return false;
        }
        Arrays.sort(nums);
        int count=0;
        for(int i=0;i<nums.length-1;i++){
            if(nums[i]==0){
                count++;
                continue;
            }
            if(nums[i]==nums[i+1]){
                return false;
            }else{
                count-=nums[i+1]-nums[i]-1;
            }
        }
        return count>=0;    
            
    }
}
```
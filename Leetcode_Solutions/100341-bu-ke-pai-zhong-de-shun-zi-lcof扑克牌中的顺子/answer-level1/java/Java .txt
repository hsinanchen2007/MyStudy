### 解题思路
先遍历一遍，记录0的个数，以及除0之外的最小值，并将所有数装入map中；
再遍历一遍，判断每次最小的数加一是否存在于map中。不存在就判断是否还有0，没有返回false。循环到数组长度也就是顺子的长度时，返回true；


### 代码

```java
class Solution {
    public boolean isStraight(int[] nums) {
        int length = nums.length;
        int countZero= 0;
        int countMin = 15;
        Map<Integer,Integer> map = new HashMap();
        for(int i =0;i<length;i++){
            if(nums[i]==0) countZero++;
            if(nums[i]<countMin && nums[i]!=0) countMin = nums[i];
            map.put(nums[i],nums[i]);
        }
        int count = 1;
        while(true){
            countMin++;
            if(map.get(countMin)==null){
                if(countZero>0){
                    countZero--;
                }else{
                    return false;
                }
            }
            count++;
            if(count ==length){
                return true;
            }

        }
    }
}
```
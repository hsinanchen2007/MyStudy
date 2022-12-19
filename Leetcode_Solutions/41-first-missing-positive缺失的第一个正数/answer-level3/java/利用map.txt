### 解题思路
把原数组保存到map中，在i=1；若map.get(i)==null,返回i,else i++

### 代码

```java
class Solution {
    public int firstMissingPositive(int[] nums) {
        Map<Integer,Integer> map=new HashMap();
        for(int i=0;i<nums.length;i++){
            map.put(nums[i],nums[i]);
        }
        int result;
        for(int i=1;;i++){
            if(map.get(i)==null){
                result=i;
                break;
            }
        }
        return result;
    }
}
```
### 代码

```java
class Solution {
    public int findRepeatNumber(int[] nums) {
        if(nums.length == 0) return -1;
        HashMap<Integer,Integer> hashMap = new HashMap<>();
        for(int num:nums){
            if(hashMap.containsKey(num)){
                return num;
            }else{
                hashMap.put(num,1);
            }
        }
        return -1;
    }
}
```
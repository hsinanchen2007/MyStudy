### 解题思路
利用HashSet
### 代码

```java
class Solution {
    public int missingNumber(int[] nums) {
        Set<Integer> resSet = new HashSet<>();
        Set<Integer> set = new HashSet<>();
        //提供的数组
        for(int num:nums){
            set.add(num);
        }
        for(int i=0;i<=nums.length;i++){
            resSet.add(i);
        }
        resSet.removeAll(set);
        Iterator<Integer> it = resSet.iterator();
        while(it.hasNext()){
            return it.next();
        }
        return -1;
    }
}
```
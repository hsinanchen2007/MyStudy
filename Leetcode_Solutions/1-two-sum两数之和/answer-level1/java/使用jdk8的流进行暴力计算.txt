### 解题思路
首先把数组转list，通过list找出余数的下标：1 如果余数下标存在就满足计算，否则重新来过

### 代码

```java
class Solution {
    public int[] twoSum(int[] nums, int target) {
        int [] retIndex = null;
        List<Integer> listData = Arrays.stream(nums).parallel().map(Integer::valueOf).boxed().collect(Collectors.toList());
        for(int i=0; i< nums.length ; i++){
            int item = nums[i];
            Integer tmp = target-item;
            int index = listData.lastIndexOf(tmp);
            //listData.contains(tmp);
            if(index<0 || index==i){
                continue;
            }
            retIndex = new int[2];
            retIndex[0] = i;
            retIndex[1] = index;
            break;
        }
        return retIndex;
    }
}
```
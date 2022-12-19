### 解题思路
新建一个ArrayList把结果存进去，再将ArrayList转成int数组

### 代码

```java

class Solution {
    public int[] decompressRLElist(int[] nums) {
        List<Integer> list = new ArrayList<Integer>();
        for(int i=0 ; i<nums.length ; i=i+2){
            for(int k=1 ; k<=nums[i] ; k++){
                list.add(nums[i+1]);
            }
        }
        int[] ans = list.stream().mapToInt(Integer::valueOf).toArray();
        return ans;
    }
}
```
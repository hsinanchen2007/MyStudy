迭代，统计前一次添加的集合，若数字和前一个数字相等，只需要在前一个集合的基础上添加就好。



### 代码

```java
class Solution {
    static  public List<List<Integer>> subsetsWithDup(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> list = new ArrayList<List<Integer>>(){{add(new ArrayList<Integer>());}};
        int count = 0;
        for (int i = 0; i <nums.length; i++) {
            int size = i>0&&nums[i]==nums[i-1]?list.size()-count:0;
            count=0;
            int len = list.size();
            for (int j = size; j<len; j++) {
                List<Integer> suSets = new ArrayList<>(list.get(j));
                suSets.add(nums[i]);
                list.add((suSets));
                count++;
            }
        }
        return list;
    }
}
```
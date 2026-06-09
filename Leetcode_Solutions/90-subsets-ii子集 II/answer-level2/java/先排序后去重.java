### 解题思路
使用78题的代码，对78题的结果先排序，后去重

### 代码

```java
import static java.util.Collections.sort;

class Solution {
    // 先排序后去重
    public static List<List<Integer>> subsetsWithDup(int[] nums) {
        List<List<Integer>> subsets = subsets(nums);
        List<Integer> lst = new ArrayList<>();
        HashSet<List<Integer>> set = new HashSet<>();
        for (int i = 0; i < subsets.size(); i++) {
            lst = subsets.get(i);
            sort(lst);
        }
        for (int i = 0; i < subsets.size(); i++) {
            set.add(subsets.get(i));
        }
        subsets.clear();
        for (Iterator<List<Integer>> it = set.iterator(); it.hasNext(); ) {
            List<Integer> list = it.next();
            subsets.add(list);
        }
        return subsets;
    }

        // 78题代码
        public static List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        List<Integer> lst = new ArrayList<>();
        if(nums.length==0){
            result.add(lst);
            return result;
        }

        int first = nums[0];
        int[] sub_nums = new int[nums.length-1];
        for (int i = 0; i < sub_nums.length; i++) {
            sub_nums[i] = nums[i+1];
        }
        List<List<Integer>> sub_result = subsets(sub_nums);
        System.out.println(sub_result);
        for (int i = 0; i < sub_result.size(); i++) {
            List<Integer> sub_lst = sub_result.get(i);
            result.add(new ArrayList<>(sub_lst));
//            if(notIn(first,sub_lst)){
                sub_lst.add(first);
                result.add(sub_lst);
//            }
        }
        return result;
    }
}
```
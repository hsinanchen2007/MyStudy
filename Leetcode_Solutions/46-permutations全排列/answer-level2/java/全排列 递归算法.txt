### 解题思路
我们从数学角度去考虑全排列 有几种情况，比如是3个数的全排列就相当于把三个编号的球放在三个桶中，
第一个桶中能放 可能是 3，放好第一个桶，第二个桶从生下的 2个中取一个因此得到全排列的算法
从n个中取一个，等价于for循环遍历，取出后，从剩下的 在去取，就等价于排除掉 当前元素 ，递归调用

### 代码

```java
class Solution {
        public List<List<Integer>> permute(int[] nums) {
       return premute(nums,new Stack<Integer>());
        
    }
    
    public List<List<Integer>> premute(int[] nums, Stack<Integer> stack){
        List<List<Integer>> lists = new ArrayList<List<Integer>>();
        if (nums.length == 0){
            Integer[] arrs = new Integer[stack.size()];
            stack.copyInto(arrs);
            lists.add(Arrays.asList(arrs));
            return lists;
        }
        for (int i=0;i< nums.length;i++){
            stack.push(nums[i]);
            int[] newNums = new int[nums.length -1];
            int index= 0;
            for (int k=0;k<nums.length;k++){
                if (k != i){
                    newNums[index++] = nums[k];
                }
            }
            lists.addAll(premute(newNums,stack));
            stack.pop();
        }
        return lists;
    }
}
```
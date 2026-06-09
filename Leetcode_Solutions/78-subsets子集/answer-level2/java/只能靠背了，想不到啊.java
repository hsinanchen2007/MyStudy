### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
   public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> output = new ArrayList();
        output.add(new ArrayList<Integer>());
        /**
         * 大致过程如下
         * []
         * [1]
         * [] [1] + [ 2] [1 2]
         * [] [1] [ 2] [1 2] + [3] [1 3] [ 2 3] [1 2 3]
         */
        for (Integer n :
                nums) {
            int size = output.size();// size 在每一个循环中都是变化的，都会增大
            for (int i = 0; i < size; i++) {
                List<Integer> subset =  new ArrayList<Integer>(output.get(i));
                subset.add(n);
                output.add(subset);
            }
        }
        return output;
   }
}
```
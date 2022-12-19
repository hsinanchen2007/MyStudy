### 解题思路
关于执行用时，还是很看运气的，同一段代码从99-67%都是可能的

思路就是
- 先排序
- 找出最小差值
- 根据最小差值找到每一对

要注意，最小差值一定是相邻的两个元素~~

要加强的是List<List<Integer>>，本质就是一层嵌套一层。要记得的是相关的方法，其实也没几个 ，至少要知道。

### 代码

```java


class Solution {
    public List<List<Integer>> minimumAbsDifference(int[] arr) {

        List<List<Integer>> ans = new ArrayList<List<Integer>>();

        int min = Integer.MAX_VALUE;
        int[] count = new int[arr.length];

        Arrays.sort(arr);
        
        for(int i = 1; i < arr.length; i++){
            count[i] = Math.abs(arr[i] - arr[i - 1]);
            min = (count[i] < min) ? count[i] : min;
        }

        for(int i = 1; i < count.length; i++){
            if(count[i] == min){
                List<Integer> cp = new ArrayList<>();
                cp.add(arr[i - 1]);
                cp.add(arr[i]);
                ans.add(cp);
            }
        }

        return ans;

    }
}
```
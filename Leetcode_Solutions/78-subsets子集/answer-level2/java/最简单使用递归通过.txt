### 解题思路
1. 这显然是递归，存在局部最优解
2. 数组中每一个元素都可以看作是前边的元素的所有子集合+自己构成的新集合
3. 举个例子，数组1,2,3。 3可以看作是和1，2的所有子集合的集合，1和2构成的子集合就是1 2  1,2
4. 那么构成的1，2，3构成的子集合就是上述子集合 加上  子集合中每一项和3 构成的新集合
5. 注意处理空集，空集是任何集合的子集
具体请看代码注释

### 代码

```java
class Solution {

    // 这个是入栈调用次数，用来处理空集合使用
    int callTimes = 0;

    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> results = new LinkedList<>();
        if(nums.length == 1){
            List<Integer> list = new LinkedList<>();
            list.add(nums[0]);
            results.add(list);
            // 如果没有发生过递归调用
            if(callTimes == 0){
                // 就加上空集
                results.add(new LinkedList<Integer>());
            }
            return results;
        }
        // 去掉数组头
        int head = nums[0];

        // 递归入栈，增加调用次数1，代表多了一次递归
        callTimes++;
        List<List<Integer>> tmpResults = subsets(Arrays.copyOfRange(nums,1,nums.length));

        // 从递归中退出，次数减少1，代表返回
        callTimes--;

        // 本次递归调用所有的集合都是最终集合的子集一部分
        results.addAll(tmpResults);

        // 将取得的上一个递归之后的集合遍历
        for(List<Integer> ls : tmpResults){
            // 切记要初始化复制，不能直接加，否则会改变原来的集合内容
            List<Integer> myItem = new LinkedList<>(ls);
            // 在复制出来的集合中加入本次的元素
            myItem.add(head);
            // 然后加入到最终结果集合中
            results.add(myItem);
        }
        // 将自己的值作为一个单独的子集
        List<Integer> me = new LinkedList<>();
        me.add(head);
        results.add(me);

        // 处理出栈加入空集
        if(callTimes == 0){
            results.add(new LinkedList<Integer>());
        }
        return results;
    }
}
```
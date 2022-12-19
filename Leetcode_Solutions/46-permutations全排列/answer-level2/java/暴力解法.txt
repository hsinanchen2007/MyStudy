### 解题思路
1. 将第一个元素加入列表
2. 将新的元素依次插入排列的中间、尾部、头部（每次插入都生成一个新的列表加入到列表集合中）
3. 重复2直至将该元素遍历完列表集合中现有的列表

[1,2,3]
1) lists = [[1]]  => init
2) lists = [[1,2],[2,1]]  => loop1 
3) lists = [[1,3,2],[1,2,3],[3,1,2],  [2,3,1],[2,1,3],[3,2,1]]  => loop2

### 代码

```java
class Solution {
    public List<List<Integer>> permute(int[] nums) {
        // 没有数字则返回空的列表
        List<List<Integer>> lists = new ArrayList<>();
        if (nums.length < 1) {
            return lists;
        } 
         // 只有一个数字则返回只有该数字的列表
        List<Integer> first = new ArrayList<>();
        first.add(nums[0]);
        lists.add(first);
        if (nums.length == 1) {
            return lists;
        }
        // 超过两个数字
        for (int i=1; i< nums.length; i++) {
            lists = insertOneNum2Lists(lists, nums[i]);    
        }
        return lists;
    }

    public List<List<Integer>> insertOneNum2Lists(List<List<Integer>> lists, Integer num) {
        List<List<Integer>> res = new ArrayList<>();
        for(List<Integer> l:lists) {
            // 在所有排列中插入新的数字
            for (int i = 0; i< l.size()-1; i++) {
                List<Integer> tmp2 = new ArrayList<>();
                tmp2.addAll(l.subList(0, i+1));
                tmp2.add(num);
                tmp2.addAll(l.subList(i+1, l.size()));
                res.add(tmp2);
            }
            // 在最后加上新的数字
            List<Integer> tmp3 = new ArrayList<>();
            tmp3.addAll(l);
            tmp3.add(num);
            res.add(tmp3);
            // 在首位加上新的数字
            List<Integer> tmp = new ArrayList<>();
            tmp.add(num);
            tmp.addAll(l);
            res.add(tmp);
        }
        return res;
    }
}
```
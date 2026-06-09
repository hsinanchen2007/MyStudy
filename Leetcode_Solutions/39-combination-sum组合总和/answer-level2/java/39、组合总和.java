### 解题思路
方法1：回溯
参考：https://leetcode-cn.com/problems/combination-sum/solution/hui-su-suan-fa-jian-zhi-python-dai-ma-java-dai-m-2/
https://leetcode-cn.com/problems/combination-sum/solution/hui-su-suan-fa-tao-mo-ban-ji-ke-by-jeromememory/；
代码过程：
![1.png](https://pic.leetcode-cn.com/e45ac7f795bde3a25ff6a96e4c70c2d8f5e7bc53b9b87fd72b369e954f59028f-1.png)
![4.png](https://pic.leetcode-cn.com/7f43e759805d1bae8abb0f735e79cb02df3cef9385b025301d0c2e818f920e8f-4.png)

### 代码

```java
class Solution {
    private List<List<Integer>> res = new ArrayList<>();
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        LinkedList<Integer> track = new LinkedList<>();
        //排序
        Arrays.sort(candidates);
        findpath(candidates, target, track, 0);
        return res;
    }
    public void findpath(int[] candidates, int target, LinkedList<Integer> track, int index){
        if(target == 0){
            res.add(new ArrayList(track));
            return;
        }
        //index为此分支下，上一减数的下标
        for(int i = index; i < candidates.length; i ++){
            if(target < candidates[i]){break;}
            track.add(candidates[i]);
            findpath(candidates, target - candidates[i], track, i);
            track.removeLast();     
        }
    }
}
```
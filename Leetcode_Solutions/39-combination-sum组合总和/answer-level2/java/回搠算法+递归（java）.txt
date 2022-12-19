详细的解释在代码中已经注释了的

```
class Solution {
            List<List<Integer>> lists = new ArrayList<List<Integer>>();
            public List<List<Integer>> combinationSum(int[] candidates, int target) {
                //用来存储每一步的数字
                List<Integer> list = new ArrayList<Integer>();
                //参数解释（数组，开始索引，存储步骤的集合，每一步累计的和，目标和）
                DFS(candidates,0,list,0,target);
                return lists;
            }

    private void DFS(int[] candidates, int index, List<Integer> list, int sum,int target) {
        if (index >= candidates.length || sum > target ){
            return ;
        }
        //如果满足条件，则list中存的数组满足条件，需要新建对象存储，原因就是list是引用
        if (sum == target){
            List<Integer> e = new ArrayList<Integer>();
            e.addAll(list);
            lists.add(e);
            return;
        }
        //以index为起点，就是考虑了去重的问题，且考虑到了数字可以多次使用的条件
        for (int i = index; i < candidates.length; i++) {
                //这个可以剪枝
              if (candidates[i] > target){
                continue;
            }   
            //存放当前步骤
            list.add(candidates[i]);
            //进行下一层的判断
            DFS(candidates,i,list,sum + candidates[i],target);
            //这里为什么要去掉最后一个元素，释放当前步骤，这里是回搠的关键了，当上面添加了元素，且执行了里层的DFS，回到这一步，要去掉元素，继续尝试下一个元素
            list.remove(list.size()-1);
        }
    }
}
```

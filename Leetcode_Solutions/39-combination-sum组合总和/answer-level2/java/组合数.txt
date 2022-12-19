### 解题思路
典型的回溯法：
递归跳出的条件
return

满足题目条件
将list加入容器
else 未满足条件：
for（遍历给出的所有变量）{
（为了去重，往往加start，来控制递归，遍历之后的元素）
将元素加入到list
递归这个函数
去除当前list的最后一个元素
}

回溯原理类似树，不断的选择，剪枝，直到把所有结果都遍历到
![image.png](https://pic.leetcode-cn.com/56ef87ff9ff3d91a8cffcffa32e1b036edf9a24979f55ee1cb90ba04de2351b0-image.png)


### 代码

```java
class Solution {
     List<List<Integer>> res=new ArrayList<>();
     public List<List<Integer>> combinationSum(int[] candidates, int target) {
         if (candidates == null || candidates.length == 0 || target < 0) {
            return res;
        }

        int start=0;
         List<Integer> list=new ArrayList<>();
         digui(start,target,candidates,list);

         return res;
     }
     public void digui(int start,int target,int [] candidates,List<Integer> list){
         if(target<0) 
             return;
          if(target==0){
             res.add(new ArrayList<>(list));
          }else {
              for(int i=start;i<candidates.length;i++){//不用去重
                  list.add(candidates[i]);
                  digui(i,target-candidates[i],candidates,list);
                  list.remove(list.size()-1);//溯回,去数组的最后一个元素
              }
          }
     }
}
```
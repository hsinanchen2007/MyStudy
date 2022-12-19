极为经典的回溯题目

思路：套用模板即可，需要说明的是：

1. 循环的起点，元素可以重用，并且不允许答案重复，起点选择当前元素。

2. 终止条件：当target等于0，那么就存在一组解；如果target不为0，需要判断target与可用元素最小值（就是当前元素），判断是否还可能出现解，不可能就进行剪枝，已经包括了target被减为负值的情况。
```
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> answer=new ArrayList<>();
        if (candidates == null || candidates.length == 0 || target <= 0) {
            return answer;
        }

        //这里是为了求最小值
        Arrays.sort(candidates);
        combinationSumCore(0,candidates,target,candidates[0],new ArrayList<>(),answer);
        return answer;
    }

    public void combinationSumCore(int first, int[] cadidates, int target, int min,
                               List<Integer> currAns, List<List<Integer>> answer){
        if(target==0){
            //出现一组解
            answer.add(new ArrayList<>(currAns));
            return;
        }

        if(target<min){
            //不可能出现解，剪枝
            return;
        }

        for(int i=first;i<cadidates.length;i++){
            currAns.add(cadidates[i]);
            combinationSumCore(i,cadidates,target-cadidates[i],cadidates[i],currAns,answer);
            currAns.remove(currAns.size()-1);
        }
    }
```

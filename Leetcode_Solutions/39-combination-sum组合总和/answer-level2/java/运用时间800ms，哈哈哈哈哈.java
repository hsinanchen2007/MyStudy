思路
    1. 找出数组中最多多少元素可以组成target
    2. 如果给定一个数目，也就是说找出数组中确切个数的元素来组成target
    3. 去重
```java
class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        if (candidates.length == 0)
            return new ArrayList<>();
        Arrays.sort(candidates);
        List<List<Integer>> res = new ArrayList<>();
        int maxCount = target / candidates[0];
        for (int i = 0; i < maxCount; i++){
            List<List<Integer>> tmp = getCombinationSum(candidates, target, i + 1);
            if (tmp != null)
                res.addAll(tmp);
        }

        List<List<Integer>> removeTmp = new ArrayList<>();
        for (int i = 0; i < res.size(); i++){
            for (int j = i + 1; j < res.size(); j++){
                if (res.get(i).size() != res.get(j).size()){
                    break;
                }
                List<Integer> ilist = res.get(i);
                List<Integer> jlist = res.get(j);
                if (isSame(ilist, jlist)){
                    removeTmp.add(ilist);
                    break;
                }
            }
        }

        res.removeAll(removeTmp);

        return res;
    }

    public boolean isSame(List<Integer> a, List<Integer> b){
        int[] aint = new int[a.size()];
        int[] bint = new int[b.size()];
        for (int i = 0; i < a.size(); i++){
            aint[i] = a.get(i);
        }
        for (int i = 0; i < b.size(); i++){
            bint[i] = b.get(i);
        }
        Arrays.sort(aint);
        Arrays.sort(bint);
        boolean res = true;
        for (int i = 0; i < aint.length; i++){
            if (aint[i] != bint[i]){
                res = false;
                break;
            }
        }

        return res;
    }

    public List<List<Integer>> getCombinationSum(int[] candidates, int target, int count){
        if (count == 1){
            int j = getIndex(candidates, target);
            if (j == -1)
                return null;
            List<List<Integer>> lists = new ArrayList<>();
            List<Integer>list2 = new ArrayList<>(1);
            list2.add(candidates[j]);
            lists.add(list2);
            return lists;
        }
        if (count == 2){
            List<List<Integer>> lists = new ArrayList<>();
            for (int i = 0; i < candidates.length; i++){
                for (int j = i; j < candidates.length; j++){
                    if (candidates[i] + candidates[j] == target){
                        List<Integer>list2 = new ArrayList<>(2);
                        list2.add(candidates[i]);
                        list2.add(candidates[j]);
                        lists.add(list2);
                    }else if (candidates[i] + candidates[j] > target){
                        break;
                    }

                }
            }
            return lists;
        }

        if (count == 3){
            List<List<Integer>> lists = new ArrayList<>();
            for (int i = 0; i < candidates.length; i++){
                for (int j = i; j < candidates.length; j++){
                    for (int k = j; k < candidates.length; k++) {
                        if (candidates[i] + candidates[j] + candidates[k] == target) {
                            List<Integer> list2 = new ArrayList<>(2);
                            list2.add(candidates[i]);
                            list2.add(candidates[j]);
                            list2.add(candidates[k]);
                            lists.add(list2);
                        } else if (candidates[i] + candidates[j] + candidates[k] > target) {
                            break;
                        }
                    }
                }
            }
            return lists;
        }

        List<List<Integer>> res = new ArrayList<>();
        for (int i = 0; i < candidates.length; i++){
            List<List<Integer>> list = getCombinationSum(candidates, target - candidates[i], count - 1);
            if (list != null){
                for (int j = 0; j < list.size(); j++){
                    List<Integer> tmp = list.get(j);
                    tmp.add(candidates[i]);
                }
                res.addAll(list);
            }
        }
        return res;
    }

    public int getIndex(int[] candidates, int target){
        // 2 3 5
        // 0 3 1
        // 0 0 1
        int start = 0, end = candidates.length, middle = (end + start) / 2;
        while (start < end - 1){
            if (candidates[middle] == target){
                return middle;
            }else if (candidates[middle] < target){
                start = middle;
            }else {
                end = middle;
            }
            middle = (end + start) / 2;
        }
        if (candidates[start] == target){
            return 0;
        }
        return  -1;
    }
}

```
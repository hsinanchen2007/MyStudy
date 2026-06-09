
```
class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> res = new ArrayList<>();
        if(candidates == null || candidates.length == 0 || target == 0){
            return res;
        }
        Arrays.sort(candidates);
        List<Integer> list = new ArrayList<>();
        int num = target;
        int count = 0;
        int[] arr_index = new int[target/candidates[0]+1];
        while(count >= 0 && arr_index[count] < candidates.length){
            int index = arr_index[count];
            if(num > candidates[index]){
                num = num - candidates[index];
                list.add(candidates[index]);
                count++;
                arr_index[count] = index;
            }else{
                if(num == candidates[index]){
                    list.add(candidates[index]);
                    res.add(new ArrayList<>(list));
                    list.remove(list.size()-1);
                }
                if(--count >= 0){
                    while(arr_index[count] >= candidates.length - 1){
                        num += list.remove(list.size()-1);
                        if(--count < 0){
                            break;
                        }
                    }
                    if(count >= 0){
                        num += list.remove(list.size()-1);
                        arr_index[count] += 1;
                    }
                }
            }
        }
        return res;
    }
}
```

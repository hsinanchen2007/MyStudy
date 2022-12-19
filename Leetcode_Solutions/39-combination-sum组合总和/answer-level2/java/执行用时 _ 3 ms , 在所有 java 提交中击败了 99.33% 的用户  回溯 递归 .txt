

class Solution {
     public void searchTarget(int[] candidates, int target, int start, int temp, List<List<Integer>> resultList, List<Integer> tempList) {
        int addNum = temp;
        int  size=0;
        int  len = candidates.length;
        for (int i = start; i < len; i++) {
            addNum += candidates[i];
            tempList.add(candidates[i]);
           if(candidates[i]>target){break;}
            if (addNum < target) {
                if (addNum + candidates[i] <= target) {
                    searchTarget(candidates, target, i, addNum, resultList, tempList);
                    for (int j = i + 1; j < len; j++) {
                        if (addNum + candidates[j] <= target) {
                            searchTarget(candidates, target, j, addNum, resultList, tempList);
                        }
                    }
                }
            }
            if (addNum == target) {
                resultList.add(new ArrayList<>(tempList));
            }
            size = tempList.size();
            tempList.remove(size- 1);
            if (size > 1) {
                break;
            }
            addNum = temp;
        }
    }

    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> resultList = new ArrayList<>();
        List<Integer> tempList = new ArrayList<>();
        Arrays.sort(candidates);
        searchTarget(candidates, target, 0, 0, resultList, tempList);
        return resultList;
    }
}
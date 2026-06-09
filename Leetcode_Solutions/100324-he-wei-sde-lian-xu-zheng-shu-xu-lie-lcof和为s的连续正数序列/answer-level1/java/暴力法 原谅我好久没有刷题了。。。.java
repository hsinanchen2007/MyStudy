```
class Solution {
    public int[][] findContinuousSequence(int target) {
        List<int[]> result = new ArrayList<>();
        int[] temp = new int[target+1];
        for(int i = 1; i < target; i++){
            int total = i;
            temp[i] = i;
            for(int j = i+1; j < target; j++){
                total += j;
                temp[j] = j;
                if(total == target){
                    int[] tempResult = new int[j-i+1];
                    for(int x = i; x <= j; x++){
                        tempResult[x-i] = temp[x];
                    }
                    result.add(tempResult);
                    break;
                } else if(total > target){
                    break;
                }
            }
        }
        int[][] intResult = new int[result.size()][];
        result.toArray(intResult);
        return intResult;
    }
}
```

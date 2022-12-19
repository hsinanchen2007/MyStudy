```
class Solution {
    int backtrack(int[] rating, int i, List<Integer>curr){
        if(curr.size() == 3){
            return 1;
        }
        int res = 0;
        for(; i < rating.length; i++){
            if(curr.size() == 0 || rating[i] > curr.get(curr.size() - 1)){
                curr.add(rating[i]);
                res += backtrack(rating, i + 1, curr);
                curr.remove(curr.size() - 1);
            }
        }
        return res;
    }

    void reverse(int[] rating){
        int start = 0, end = rating.length - 1;
        while(start < end){
            int t = rating[start];
            rating[start] = rating[end];
            rating[end] = t;
            start += 1;
            end -= 1;
        }
    }
    
    public int numTeams(int[] rating) {
        int res = 0;
        res += backtrack(rating, 0, new ArrayList<Integer>());
        reverse(rating);
        res += backtrack(rating, 0, new ArrayList<Integer>());
        return res;
    }
}
```

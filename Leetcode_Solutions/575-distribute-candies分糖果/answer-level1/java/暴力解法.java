```
class Solution {
    public int distributeCandies(int[] candies) {
        int[] sister = new int[candies.length];
        List<Integer> kind = new ArrayList<Integer>();
        int maxKind = 0;
        for(int i = 0; i < candies.length; i++){
            if(!kind.contains(candies[i])){
                kind.add(candies[i]);
            }
        }
        if(kind.size() <= candies.length / 2){
            maxKind = kind.size();
        }else{
            maxKind = candies.length / 2; 
        }

        return maxKind;
    }
}
```

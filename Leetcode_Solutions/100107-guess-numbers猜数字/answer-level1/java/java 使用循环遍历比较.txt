```
class Solution {
    public int game(int[] guess, int[] answer) {
        int count=0;
        for(int i=0;i<3;i++){
            if(guess[i]==answer[i]){
                count++;
            }
        }
        return count;
    }
}
```

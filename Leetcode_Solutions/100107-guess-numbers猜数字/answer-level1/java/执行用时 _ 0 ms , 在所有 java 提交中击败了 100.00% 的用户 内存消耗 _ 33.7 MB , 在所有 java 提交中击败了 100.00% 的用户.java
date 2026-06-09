



class Solution {
    public int game(int[] guess, int[] answer) {

        int total = 0;
        int i = 0, j = guess.length - 1;
        while(i <= j){
            if(guess[i] == answer[i]){
                total++;
            }
            if(i != j && guess[j] == answer[j]){
                total++;
            }
            ++i;
            --j;
        }
        return total;
    }
}
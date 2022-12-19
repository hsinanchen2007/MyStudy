class Solution {
    public int game(int[] guess, int[] answer) {
        int result = 0;
        for(int i = 0 ; i< 3; i++){
                if(guess[i] == answer[i]){
                    result+=1;

                }
        }
        return result;
    }
}
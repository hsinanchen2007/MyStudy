int game(int* guess, int guessSize, int* answer, int answerSize){
    if (answer == NULL || guess == NULL) {
       return -1;
    }
    int k = 0;
       for(int i = 0; i < guessSize; ++i){
           if(guess[i] == answer[i] && i < answerSize) {
              k++;
           }
       }
       return k;
}
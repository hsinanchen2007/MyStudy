int game(int* guess, int guessSize, int* answer, int answerSize){
    int resultData =0;
    for (int i=0;i<guessSize;i++){
        !(guess[i]^answer[i])?resultData++:0;
    }
    return resultData;

}
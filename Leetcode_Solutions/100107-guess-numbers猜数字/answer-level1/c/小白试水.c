int game(int* guess, int guessSize, int* answer, int answerSize){
        int a=0;
        for(int i=0; i<guessSize; i++)
        {
            if(*(guess+i) == *(answer+i))
            ++a;
        }
        return a;
}
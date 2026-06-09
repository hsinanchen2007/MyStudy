迄今为止，最好做的一个
        int count=0;
        for(int i=0;i<guess.length;i++){
            if(guess[i]==answer[i]){
                ++count;
            }
        }
        return count;
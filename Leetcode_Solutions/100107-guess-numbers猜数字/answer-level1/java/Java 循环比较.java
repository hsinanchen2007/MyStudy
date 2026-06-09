```
    public int game(int[] guess, int[] answer) {
        int num = 0;
        for (int i = 0; i < guess.length; i++) {
            if (guess[i] == answer[i]){
                num ++;
            }
        }
        return  num;
    }
```

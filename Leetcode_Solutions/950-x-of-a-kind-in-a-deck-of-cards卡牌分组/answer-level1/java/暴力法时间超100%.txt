```
class Solution {
    public boolean hasGroupsSizeX(int[] deck) {
        if(deck.length<2) return false;
        int maxj=0;
        for(int i = 0,length=deck.length ;i<length;i++){
                if(maxj<deck[i]) maxj=deck[i];
        }
        int[] bool = new int[maxj+1];
        int min=10000;
        for(int i = 0,length=deck.length ;i<length;i++){
            bool[deck[i]]++;
        }
        for(int i=0;i<=maxj;i++){
            if(bool[i]!=0){
                if(min>bool[i]) min=bool[i];
            }
        }
        //System.out.println(min);
        for(int i =2;i<=min;i++){
            int b=0;
            for(int j =0;j<=maxj;j++){
                if(bool[j]%i!=0){
                    b=1;
                    break;
                }
            }
            if(b==0) return true;
        }
        return false;
    }
}


```

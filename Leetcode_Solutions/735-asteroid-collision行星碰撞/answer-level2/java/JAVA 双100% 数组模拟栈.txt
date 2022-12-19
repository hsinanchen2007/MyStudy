```
class Solution {
    public int[] asteroidCollision(int[] asteroids) {
        int[] res = new int[asteroids.length];
        int index =-1;
        for(int i=0;i<asteroids.length;i++){
            int val =asteroids[i];
            if(index == -1){
                res[++index]=val;
            }
            else{
                if(res[index]* val >0){
                    res[++index] =val;
                }
                else{
                    if(val >0)
                        res[++index] =val;
                    else{
                        if(res[index] + val <0)
                        {
                            index--;
                            i--;
                        }
                        else if(res[index] + val ==0){
                            index--;
                        }
                    }
                }
            }
        }
        int[] ans = new int[index+1];
        for(int i=0;i<=index;i++){
            ans[i]=res[i];
        }
        return ans;
    }
}
```
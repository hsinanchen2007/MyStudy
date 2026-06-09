其实就是计算种类有没有超过length/2;超过则返回一半数目，未超过则返回种类数；
```
class Solution {
    public int distributeCandies(int[] candies) {
        Arrays.sort(candies);
        int times=1;
        for(int i=0;i<candies.length-1;i++){
            if(candies[i]!=candies[i+1]){
                times++;
            }
        }
        return times>candies.length/2?candies.length/2:times;
    }
}
```

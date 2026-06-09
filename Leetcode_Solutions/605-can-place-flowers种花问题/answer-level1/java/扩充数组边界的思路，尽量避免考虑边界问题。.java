```
class Solution {
    public boolean canPlaceFlowers(int[] flowerbed, int n) {
        //扩充数组边界的思路，省去考虑很多边界的问题。
        //这个题目的思路就是连续三个0可以加一个1.但是加上1之后要填充。
        int[] temp = new int[flowerbed.length+2] ;
        temp[0] = 0 ;
        temp[temp.length-1] = 0 ;
        for(int i=1;i<temp.length-1;i++){
            temp[i] = flowerbed[i-1] ;
        }
        int result = 0 ;
        for(int i=1;i<temp.length-1;i++){
            if(temp[i-1]==0&&temp[i]==0&&temp[i+1]==0){
                //在这个地方种上1，不然很容易会出现重复值的问题。
                temp[i]=1 ;
                result++ ;
            }
        }
        return result>=n ;
    }
}
```

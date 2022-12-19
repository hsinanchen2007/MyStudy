//西撒，说出你想要的赏赐吧
//陛下，您看，我今天把西西幼儿园小班的所有小孩子带过来了
```
public class Solution {
    public int[] DistributeCandies(int candies, int num_people) {
        int i=0;
        int give=1; //give为这次我要给出的糖果数量
        int[] answer=new int[num_people];
        while(true){
            if(give<candies){
                answer[i]+=give;
                candies-=give;
                give++;
            }
            else if(give>=candies){
                answer[i]+=candies;
                return answer;
            }
            i++;
            if(i==num_people){i=0;}
        }
    }
}
```

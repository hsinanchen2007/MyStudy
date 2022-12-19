### 解题思路
引入轮数作为变量，每次判断是否糖果数为0，与标答相比，轮数值显得多余

### 代码

```java
class Solution {
public int[] distributeCandies(int candies, int num_people){
        int[] ans = new int[num_people];
        int round=0;
        while(candies>0)
        {
            for(int i=0;i<num_people;i++){

                if(candies>((i+1)+round*num_people))
                {
                    ans[i]=ans[i]+round*num_people+(i+1);

                    candies=candies-(round*num_people+(i+1));
                }else{
                    ans[i]=ans[i]+candies;
                    candies=0;
                    break;
                }


            }
            round++;

        }
        return ans;
    }
}
```
### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] distributeCandies(int candies, int num_people) {
            int[] res = new int[num_people];
            int flag = 0;
            while(candies>0){
                
                for(int i = 0;i<num_people;i++){
                    if(candies>=flag*num_people+i+1){
                        res[i]+=flag*num_people+i+1;
                        candies-=flag*num_people+i+1;
                    }else{
                        res[i]+=candies;
                        candies=0;
                        break;
                    }
                }
                flag+=1;

            }
            return res;
    }
}
```
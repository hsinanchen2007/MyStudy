### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] distributeCandies(int candies, int num_people) {
        int[] result = new int[num_people];

        int index = 0;
        int count = 0;
        while(candies > 0) {
            int getCandise = index + 1 + count * num_people;
            if(candies > getCandise) {
                result[index] += getCandise;    
            } else {
                result[index] += candies;
                break;
            }

            candies -= getCandise;
            if((index+1) % num_people == 0) {
                count++;
            }
            index = (index+1) % num_people;   
        }
        return result;
    }
}
```
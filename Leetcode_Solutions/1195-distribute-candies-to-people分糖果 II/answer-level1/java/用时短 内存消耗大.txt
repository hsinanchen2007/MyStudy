### 解题思路
总的分发过程可以看做递增数列，故先求出该递增数列的长度totalLength，即为总的分发次数。
总次数除以人数即分发轮数b，对人数求余即最后一轮发到的人数a。
对每个人的获得的糖果找规律求和即可，只有最后获得糖果的人需要单独考虑，我这里算的很麻烦，多拎了个函数求差值。

### 代码

```java
class Solution {
    public int[] distributeCandies(int candies, int num_people) {
        int totalLength = TotalLength(candies);
        int a = totalLength % num_people;
        int b = totalLength / num_people;
        int result[] = new int[num_people];

        for (int i=0;i<a;i++){
            result[i] = (b+1)*(i+1) + b*(b+1)*num_people/2;
        } 

        for (int i=a;i<num_people;i++){
            result[i] = b*(i+1) + b*(b-1)*num_people/2;
        }
        
        //要考虑a可能为0，所以不能用 a-1 来算
        result[(a+num_people-1)%num_people] = result[(a+num_people-1)%num_people] - minus(candies);

        return result;
    }

    public int TotalLength(int candies){
        for(int i=1; ;i++){
            if(i*(i+1)/2 >= candies)
                return i;
        }
    }

    public int minus(int candies){
        for(int i=1; ;i++){
            if(i*(i+1)/2 >= candies)
                return (i*(i+1)/2 - candies);
        }
    }
}
```
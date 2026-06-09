### 解题思路
发糖果的过程可以分为完整轮和不完整轮，下面推导k个完整轮的糖果总数公式：
- 第 1 轮糖果总数：$1 + 2 + 3 + ... + n = 0*n^2 + n^2/2 + n/2$
- 第 2 轮糖果总数：$(n+1) + (n+2) + (n+3) + ... + (n+n) = 1*n^2 + n^2/2 + n/2$
- 第 3 轮糖果总数：$(2n+1) + (2n+2) + (2n+3) + ... + (2n+n) = 2*n^2 + n^2/2 + n/2$
- ......
- 第 k 轮糖果总数：$((k-1)n+1) + ((k-1)n+2) + ((k-1)n+3) + ... + ((k-1)n+n) = (k-1)*n^2 + n^2/2 + n/2$

所以，k 个完整轮的糖果总数为：
$(0*n^2 + n^2/2 + n/2) + (1*n^2 + n^2/2 + n/2) + (2*n^2 + n^2/2 + n/2) + ... + ((k-1)*n^2 + n^2/2 + n/2)$
$= (0 + 1 + 2 + ... + (k-1))*n^2 + k(n^2/2 + n/2)$
$= (k^2*n^2 + k*n) / 2$

通过上述公式可以计算出完整轮的个数，将完整轮的糖果分发完后，在依次分发不完整轮的糖果。


### 代码

```cpp
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> result(num_people, 0);

        // 计算给所有人发糖果可以发多少轮
        int k = 0, sum = 0;
        while(sum <= candies){
            ++k;
            sum = (k*k*num_people*num_people + k*num_people) / 2;
        }
        int round = k - 1;

        // 发完整轮数的糖果
        for(int j = 0; j < num_people; ++j){
            result[j] = (round*round - round)*num_people/2 +round*(j+1);
        }
        candies -= (round*round*num_people*num_people + round*num_people) / 2;

        // 发不完整轮数的糖果
        int i = 0;
        while(candies > 0){
            int can = round*num_people + i + 1;
            if(candies > can){
                result[i++] += can;
                candies -= can; 
            }else{
                result[i] += candies;
                candies = 0; 
            }
        }
        return result;
    }
};
```
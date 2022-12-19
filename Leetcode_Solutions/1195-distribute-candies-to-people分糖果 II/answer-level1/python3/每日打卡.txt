## 思路
首先是我自己的思路，即正常循环遍历，每分一次判断一次。
1.当糖果数大于等于步数时可以正常分，此处用于while循环。
2.当糖果数小于步数时，全送给当前小朋友。
```python []
class Solution:
    def distributeCandies(self, candies: int, num_people: int) -> List[int]:
        num = num_people
        res = [0]*num 
        step = 0
        while (candies >= (step + 1)):
            res[step % num] += (step + 1)
            candies -= (step + 1)
            step += 1
        res[step % num] += candies
        return res
```
``` C++ []
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        int num = num_people;
        vector<int> res(num_people,0);
        int step = 0;
        while (candies >= (step + 1)) {
            res[step % num] += (step + 1);
            candies -= (step + 1);
            step++;
        }
        res[step % num] += candies;
        return res;
    }
};
```
## 官方题解的数学方法
1.计算完整分发份数p以及省下的数量remaining。
2.基于份数p计算每个人收到礼物的轮数rows，以及最后一轮获取完成礼物的人数col，进而根据下述公式计算完整获取礼物每个人的礼物数。d[i]=i+(i+N)+(i+2N)+...(i+(rows−1)N)=i×rows+N(rows*(rows+1))/2
其中最后一轮中，小于col部分人获得完整礼物i+N×rows，最后一人获取remaining。
```python []
class Solution:
    def distributeCandies(self, candies: int, num_people: int) -> List[int]:
        n = num_people
        # how many people received complete gifts
        p = int((2 * candies + 0.25)**0.5 - 0.5) 
        remaining = int(candies - (p + 1) * p * 0.5)
        rows, cols = p // n, p % n
        
        d = [0] * n
        for i in range(n):
            # complete rows
            d[i] = (i + 1) * rows + int(rows * (rows - 1) * 0.5) * n
            # cols in the last row
            if i < cols:
                d[i] += i + 1 + rows * n
        # remaining candies        
        d[cols] += remaining
        return d
```
```C++ []
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        int n = num_people;
        // how many people received complete gifts
        int p = (int)(sqrt(2 * candies + 0.25) - 0.5);
        int remaining = (int)(candies - (p + 1) * p * 0.5);
        int rows = p / n, cols = p % n;

        vector<int> d(n, 0);
        for (int i = 0; i < n; ++i) {
            // complete rows
            d[i] = (i + 1) * rows + (int)(rows * (rows - 1) * 0.5) * n;
            // cols in the last row
            if (i < cols) d[i] += i + 1 + rows * n;
        }
        // remaining candies 
        d[cols] += remaining;
        return d;
    }
};
```


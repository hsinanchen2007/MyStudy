### 解题思路
**双层循环 依此判断 更新值**
关键是双层遍历 知道每次k=num_people*n+1 (n=0;n++)
判断k和candies的大小
注意更新candies的值
res[i] += k (不是直接等于k)

### 代码

```cpp
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> res(num_people,0);
        int k;
        int n=0;
        while(candies){
            k=n*num_people+1;
            for(int i=0;i<num_people;i++){
                if(k<=candies){
                    res[i] = res[i]+k;
                    candies = candies-k;
                    k=k+1;
                }
                else{
                    res[i]+=candies;
                    candies=0;
                    break;
                }
            }
            n++;
        }
        return res;
    }
};
```
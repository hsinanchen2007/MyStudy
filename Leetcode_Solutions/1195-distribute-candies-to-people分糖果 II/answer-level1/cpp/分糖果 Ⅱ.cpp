### 解题思路
用count%num_people表示每一个孩子的下标
比较candies剩余糖果数和step每次应该给的糖果数，谁小加谁。
利用vector（n，0）进行存储
描述很复杂，代码很简单。
### 代码

```cpp
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector a(num_people,0);
        int count=0,step=1;
        while(candies>0){
            if(candies>step){
                a[count%num_people] += step;
            }
            else{
                a[count%num_people] += candies;
            }
            candies=candies-step;   //剩余糖果数先减去，然后step再++
            step++;
            count++;
        }
        return a;
    }
};
```
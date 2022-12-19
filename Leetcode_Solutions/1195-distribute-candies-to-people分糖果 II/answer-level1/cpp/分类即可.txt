### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
        vector<int>distributeCandies(int candies, int num_people) {
        vector<int>p(num_people,0);
        int need_candies = 1;
        int num_Candies = 0;
        int num = candies;
        int i = 0;
        while(num_Candies <= 2 * candies && num > 0){
            i = i %  num_people;
            if(need_candies <= num){
                p[i++] +=  need_candies;
                num = num - need_candies;
                need_candies++;
            }
            else{
                p[i++] += num;
                num = num - need_candies;
            }
        }
        return p;
    }
};
```
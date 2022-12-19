### 解题思路
一种很直观的思路是，按照n+1的顺序给孩子们递增分糖。注意以下几点细节：
1. 定义角标为angle，当给最后一个小朋友分完糖后，角标要变为初始值angle = (angle+1)%num_people。如果忽略角标的循环则会越界；
2. 记得考虑candies和num_people均为0的情况，作特殊处理；
3. 分配糖果时，没必要新建一个变量存储已分配的糖果总数，直接用candies减去分配数即可，当candies为0时，说明糖果分配完毕。

### 代码

```java
class Solution {
    public int[] distributeCandies(int candies, int num_people) {
        int[] people = new int[num_people];
        if(num_people == 0)     return people;

        for(int j=0; j<num_people; j++){
            people[j] = 0;      // 初始每个小朋友有0个糖果
        }

        int angle = 0;
        for(int i = 1; candies >= i; i++){
            people[angle] += i; 
            angle = (angle+1)%num_people;
            candies -= i;
        }

        if(candies > 0){
            people[angle] += candies;
        }

        return people;
    }
}
```
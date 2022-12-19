### 解题思路
此处撰写解题思路
需要一个数组，一个能计数目前糖果每一次发放的数量，一个下标对应小孩儿，注意循环下标越界时需要取余
### 代码

```java
class Solution {
    public int[] distributeCandies(int candies, int num_people) {
        int[] ans = new int[num_people];
        int count = 1, i = 0;
        while(candies >= count){
            if(i >= num_people)
                i = i % num_people;
            ans[i++] += count;
            candies -= count;
            count++;
        }
        ans[i % num_people] += candies;
        return ans;
    }
}
```
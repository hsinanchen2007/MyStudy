### 解题思路
如代码注释

### 代码

```java
class Solution {
    public int[] distributeCandies(int candies, int num_people) {
        int[] ans = new int[num_people];
        for(int i = 0; i<num_people;i++){
            ans[i] = 0;
        }
        int i = 0;  //i表示第i次分糖果
        int candy = 0;  //表示应该分的糖果数
        while(candies > 0){
            candy++;
            int index = i%num_people; // index是此次应该获得糖果的人的下标
            if(candy > candies){
                //如果剩余的总糖果数少于应该分的糖果数，便把剩余的总糖果数全部分给这个小朋友
                candy = candies;
            }
            ans[index] += candy;
            i++;
            candies -= candy;
        }
        return ans;
    }
}
```
### 解题思路
直接模拟。思路见注释😄
### 代码

```java
class Solution {
    public int[] distributeCandies(int candies, int num_people) {
        int[] ans = new int[num_people];
        int i = 1;  //当前要发的糖果数
        int p = 0;  //指向发糖的小朋友
        while (candies > 0) {
            if (candies >= i) {
                ans[p] += i;    //给第当前小孩分配糖果

                candies -= i;   //糖果数消耗掉i
                i+=1;           //下一个小孩发的糖果数+1
                p = (p + 1) % num_people;   //指向下一个小孩
            } else {    //最后一个小朋友糖不够发的情况
                ans[p] += candies;  //剩余糖果全部分配给小孩
                candies = 0;
            }
        }
        return ans;
    }
}
```
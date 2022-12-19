### 解题思路
首先题目中说当糖果分发完毕时结束（candies==0），并且依据题意糖果并不是只分发一轮可能有多轮，所以我觉得最外层最好建立一个while循环条件是candies!=0。又因为题中给了candies和num_pople的形参，所以能建立关于人数的数组，数组长度为num_pople。然后因为要给第一个小朋友发一个糖果，所以我建立一个整型设置初始值为1。然后开始给小朋友们分发糖果用到for循环，然后再里面添加条件，当我的剩余的糖果比我给上一个小朋友分发的糖果多时，我先减去我手中的糖果，然后给下一个小朋友加上我减去的糖果，candies++；当我的剩余的糖果比我给上一个小朋友分发的糖果少时
我就把剩余的糖果都给下一个小朋友，然后candies变为0,break跳出循环。
### 代码

```java
class Solution {
    public int[] distributeCandies(int candies, int num_people) {
        int[] ans = new int[num_people];
        int start = 1;
        while (candies != 0){
            for (int i=0;i<num_people;i++){
                if (candies-start>=0){
                    candies -= start;
                    ans[i] += start;
                    start++;
                }
                else if (candies-start<0){
                    ans[i] += candies;
                    candies = 0;
                    break;
                }
            }
        }
        return ans;
    }
}
```
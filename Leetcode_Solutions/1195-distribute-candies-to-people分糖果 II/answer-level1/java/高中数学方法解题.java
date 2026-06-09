### 解题思路
1、先理解题意，顺序发糖，直到最后发完，其实就是一个1+2+....+n+delta的问题
2、利用数学方式解出n和余数delta，即分发了n次和最后一个余数delta
3、根据num_people计算出完全发完的次数row,以及剩余的可以分发delta_count个人
4、最后，利用数学公式进行累加就好了，这种方法的用时很少，但是内存会较大

### 代码

```java
class Solution {
    public int[] distributeCandies(int candies, int num_people) {
        int[] distribute = new int[num_people];
        int count = (int) Math.floor(Math.abs(Math.sqrt(2 * candies + 0.25))-0.5);
        int delta_num = candies - (count + 1) * count / 2;
        int row = count / num_people;
        int delta_count = count % num_people;
        for (int index = 0; index < num_people; index++) {
            distribute[index] = row * (row - 1) * num_people/2 + row * (index + 1);
        }
        for (int index = 0; index < delta_count; index++) {
            distribute[index] += row * num_people + index + 1;
        }
        distribute[delta_count] += delta_num;
        return distribute;
    }
}
```
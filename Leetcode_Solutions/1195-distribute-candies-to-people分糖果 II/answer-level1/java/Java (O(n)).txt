### 解题思路
index设定为这一轮给第几个小朋友,next是给目前的小朋友多少个糖果，所以每给一次就要加一.在给完next数量的糖果后，candies就要减去对应数量的糖果
,如果next大于等于最后的candies的话，那就给剩下的小朋友加上对应candies数量的糖果，然后结束while循环。
### 代码

```java
class Solution {
    public int[] distributeCandies(int candies, int num_people) {
        if (candies <= 0 || num_people <= 0){
            return new int[]{};
        }
        int[] res = new int[num_people];
        int next = 1;
        int index = 0;
        // index设定为这一轮给第几个小朋友
        // next是给目前的小朋友多少个糖果，所以每给一次就要加一
        // 在给完next数量的糖果后，candies就要减去对应数量的糖果
        // 如果next大于等于最后的candies的话，那就给剩下的小朋友加上对应candies数量的糖果，然后结束while循环
        while (true){
            if (candies > next){
                res[index] += next;
                candies -= next++;
            } else {
                res[index] += candies;
                break;
            }
            index = (index + 1) % num_people;
        }
        return res;
    }
}
```
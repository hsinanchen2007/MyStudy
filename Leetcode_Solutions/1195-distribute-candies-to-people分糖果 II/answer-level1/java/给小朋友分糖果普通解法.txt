### 解题思路
很简单的题目，够分就count++，不够分就直接给剩余的candies，没啥好说的，注释已经写明白了

### 代码

```java
class Solution {
    public int[] distributeCandies(int candies, int num_people) {
        /*初始分发数*/
        int count = 1 ;
        /*思路：1.直接生成一个num people数组，对数组内的数据进行修改*/
        /*2.根据规律生成一堆数，再把数放到数组中.*/
        int [] a = new int[num_people];
        while (candies>0){
            if (candies>count){
                a[(count-1)%num_people] += count;
                candies-= count;
            }else{
                a[(count-1)%num_people] += candies;
                candies -= candies;
            }
            count ++ ;
        }
        return  a ;
    }
}
```
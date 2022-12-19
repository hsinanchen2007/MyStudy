### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] distributeCandies(int candies, int num_people) {
        int[] arr = new int[num_people];
        int count = 1;
        while(candies > 0){
                if(candies - count >= 0){
                    arr[(count - 1)%num_people] += count;
                    candies -= count;
                    count++;
                }else{
                    arr[(count - 1)%num_people] += candies;
                    candies = 0;
                }               
            }
        return arr;
    }
}
```
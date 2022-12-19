### 解题思路
找到分配规律，不难实现。

### 代码

```java
class Solution {
    public int[] distributeCandies(int candies, int num_people) {
        int ans[] = new int[num_people];
        int index = 0;
        int candi_num = 1;
        while(candies > 0){
            if(candies > candi_num){
                ans[index++] += candi_num;
                candies -= candi_num; 
            }else{
                ans[index++] += candies;
                candies = 0;
            }
            candi_num++;
            if(index > ans.length - 1){
                index = 0;
            }
        }
        return ans;
    }
}
```
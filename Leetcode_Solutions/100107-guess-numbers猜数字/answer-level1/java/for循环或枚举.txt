![2020030501.PNG](https://pic.leetcode-cn.com/52f152b5fbb0d91533f617fd94d797b9b72ad6ea534647c55ae1a49b9cb61d8d-2020030501.PNG)
### 解题思路
逐个比较数组guess和answer在相同索引位置处的值是否相;

由于两个数组的长度恒等于3,可以用循环法和枚举法.
### 代码

```java
class Solution {
    public int game(int[] guess, int[] answer) {
        // int cnt=0;
        // for(int i=0;i<guess.length;i++){
        //     if(guess[i]==answer[i]){
        //         cnt++;
        //     }
        // }
        // return cnt;
        return (guess[0]==answer[0]?1:0)+(guess[1]==answer[1]?1:0)+(guess[2]==answer[2]?1:0);
    }
}
```
### 解题思路
此处撰写解题思路
我的思路:
    就是统计一下这个小A和小B两个人猜的数字是否一样，直接循环遍历统计，相同的话就统计次数，直接返回Len;
### 代码

```java
class Solution {
    public int game(int[] guess, int[] answer) {
        int len=0;
        for(int i=0;i<3;i++){
            if(guess[i]==answer[i]){
                len++;
            }
        }
        return len;
    }
}
```
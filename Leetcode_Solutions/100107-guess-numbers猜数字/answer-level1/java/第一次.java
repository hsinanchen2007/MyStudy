### 解题思路
此处撰写解题思路
num用于计数，从头到尾依次对比得出答案
### 代码

```java
class Solution {
    public int game(int[] guess, int[] answer) {
        int num=0;
        for(int i=0;i<3;i++)
        {if(guess[i]==answer[i])
            num++;}
        return num;
    }
}
```
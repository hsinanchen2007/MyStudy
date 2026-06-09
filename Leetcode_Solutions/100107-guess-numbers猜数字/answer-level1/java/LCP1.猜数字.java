### 解题思路
比较猜中了几次，实际上就是求：前者数组和后者数字在位置一一对应的前提下，有几次值相同



```java
class Solution {
    public int game(int[] guess, int[] answer) {
        int n=0;//猜中的个数
        int len=guess.length;//前者的数组长度
        for(int i=0;i<len;i++){
            if(guess[i]==answer[i]) n++;//如果前者数组与后者数组元素相对应，则猜中，即n加1
            
        }
        return n;//返回去
    }
}
```
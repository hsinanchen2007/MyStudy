### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int romanToInt(String s) {
        int[] map = {100, 500, 0, 0, 0, 0, 1, 0, 0, 50, 1000, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 10};
        char[] cs = s.toCharArray();
        int num=map[cs[0]-67];
        int sum=0;
        for (int i = 1; i < cs.length; num=map[cs[i++]-67]) {
            if(num < map[cs[i]-67]){
                sum+=num*-1;
            }else {
                sum+=num;
            }
        }
        return sum + num;
    }
}
```
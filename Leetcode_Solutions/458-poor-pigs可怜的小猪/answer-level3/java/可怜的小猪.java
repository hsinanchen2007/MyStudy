### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        //数学问题
        int state=minutesToTest/minutesToDie+1;
        return (int)Math.ceil(Math.log(buckets)/Math.log(state)); //对数的换底公式
    }
}
```
### 解题思路
需要注意一点的是，把15的倍数最前面判断即可

### 代码

```java
class Solution {
    public List<String> fizzBuzz(int n) {
        //3-3的n倍
        //5-5的n倍
        //3和5的倍数 15的n倍 
        //n%m == 0 则表示n是m的倍数
        List<String> list = new LinkedList();
        
        for (int i = 1; i <= n; i++) {
            if (i%15 == 0) {
                list.add("FizzBuzz");
            } else if (i%3 == 0) {
                list.add("Fizz");
            } else if (i%5 == 0) {
                list.add("Buzz");
            } else {
                list.add(String.valueOf(i));
            }
        }

        return list;
    }
}
```
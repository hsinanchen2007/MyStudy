### 解题思路
1. 首先声明一个空的Strig集合，集合的大小为参数n；
2. 传递参数必须大于等于1；
3. 根据题目可知，能被3和5都能整除时输出“FizzBuzz”，因此先对遍历的数字取模15；
4. 能被5整除的数也有可能被3整除，比如15，因此较大的因数应该提前判断；

### 代码

```java
class Solution {
    public List<String> fizzBuzz(int n) {
        List<String> list = new ArrayList<>(n);
        for (int i = 1 ; i <= n ; i++) {
            if ( i % 15 == 0) {
              list.add("FizzBuzz");
            } else if ( i % 5 == 0 ) {
              list.add("Buzz");
            } else if ( i % 3 == 0) {
              list.add("Fizz");
            } else {
              list.add(String.valueOf(i));
            }
        }
        return list;
    }
}
```
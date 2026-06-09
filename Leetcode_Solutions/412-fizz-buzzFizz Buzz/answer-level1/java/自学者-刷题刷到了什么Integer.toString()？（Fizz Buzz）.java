### 解题思路
* 求余数
* 定型自己的思维，将整数转字符串固定为Integer.toString(i)
* 为什么不用String.valueOf(i); i=null时 字符串="null"，暂时不用。

### 代码

```java
class Solution {
    public List<String> fizzBuzz(int n) {
        List<String> sb = new LinkedList<>();
        for(int i = 1; i <= n; i++) {
            int a = i % 3;
            int b = i % 5;   
            // System.out.printf("i:%d,a:%d,b:%d\n",i,a,b);         
            if(a==0 && b==0) {
                sb.add("FizzBuzz");
            } else if(a == 0) {
                sb.add("Fizz");
            } else if(b == 0) {
                sb.add("Buzz");
            } else {
                sb.add(Integer.toString(i));   
            }
        }
        return sb;
    }
}
```
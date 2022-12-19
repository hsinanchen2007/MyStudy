### 解题思路
感觉没啥可说的，建立一个链表，通过判断不同情况，链表加入某一情况的字符串即可。

### 代码

```java
class Solution {
    public List<String> fizzBuzz(int n) {
        List<String> list = new LinkedList<String>();
        for(int i = 1;i<=n;i++) {
            if(i%3==0 && i%5!=0) {
                list.add("Fizz");
                continue;
            }
            if(i%3!=0 && i%5==0) {
                list.add("Buzz");
                continue;
            }
            if(i%3==0 && i%5==0) {
                list.add("FizzBuzz");
                continue;
            }
            list.add(""+i);

        }
        return list;
    }
}
```
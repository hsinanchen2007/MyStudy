### 解题思路
诚然，一般处理方法肯定是处理成char数组然后处理，在高级一点就是用charAt定位在处理！但是啊，replace思虑周全，啥都可以，你char，char序列或者String统统可以帮你换！真香！

### 代码

```java
class Solution {
    public String replaceSpace(String s) {
        s=s.replace(" ","%20");
        return s;
    }
}
```
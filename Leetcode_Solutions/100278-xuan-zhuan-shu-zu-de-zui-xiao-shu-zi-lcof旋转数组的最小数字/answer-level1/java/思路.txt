### 解题思路
此处撰写解题思路
我的思路:
    就是从数组中找最小值，我们定义一个Min初始值为10000000，为什么呢？
我是考虑了如果数组中有负数的情况。
    然后就是判断数组中的值是否小于我定义的这个数，如果是就赋值个它
最后返回这个最小的值;
### 代码

```java
class Solution {
    public int minArray(int[] numbers) {
        int min=100000000;
        for(int i=0;i<numbers.length;i++){
            if(numbers[i]<min){
                min=numbers[i];
            }
        }
        return min;
    }
}
```
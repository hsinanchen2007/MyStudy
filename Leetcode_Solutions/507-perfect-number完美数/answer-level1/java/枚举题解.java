### 解题思路
自己之前的题解类似暴力解法，利用额外的数组空间，动态扩容的性能开销很大。并且遍历也是从头到尾，看了官方题解后，改进了自己的暴力题解，遍历只需要从1到sqrt（n）的区间就可以了。取消了额外的数组空间。时间复杂度为O(sqrt(n)).

### 代码

```java
class Solution {
    public boolean checkPerfectNumber(int num) {
        if (num <= 0) {
            return false;
        }
        
        int sum = 0;
        for (int i = 1; i * i <= num; ++i) {
            if (num % i == 0) {
                sum += i;
                if (i * i != num) {
                    sum += num / i;
                }
            }
        }

        return sum - num == num;
    }
}
```
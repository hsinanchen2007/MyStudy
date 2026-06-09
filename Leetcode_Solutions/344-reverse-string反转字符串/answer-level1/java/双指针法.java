### 解题思路
第一个版用的是暴力法，第i次前进一个字符，字符串内部进行(i+1)次交换。时间复杂度O(N^2)，执行用时1407ms，体会一下。。
```java
class Solution {
    public void reverseString(char[] s) {
        for(int i = 0; i < s.length; i++) {
            char tmp = s[i];
            for(int j = i; j > 0; j--) {
                s[j] = s[j - 1];
            }
            s[0] = tmp;
        }
    }
}
```
发现暴力法进行了很多次无用的交换，从减少交换次数的角度，再结合题目案例的暗示，想到了一头一尾两个方向移动的双指针的想法。代码如下：
```java
class Solution {
    public void reverseString(char[] s) {
        int len = s.length;
        for(int i = 0; i < len / 2; i++) {
            // swap
            char tmp = s[i];
            s[i] = s[len - i - 1];
            s[len - i - 1] = tmp;
        }
    }
}
```
### 总结
双指针的使用很灵活，不一定是pre和cur的相邻关系同向移动，也可能类似于本地的head和tail相向移动，还可能有移动速度不同进而形成快慢指针。所以双指针的使用要见题行事，根据题目的特点，灵活使用。
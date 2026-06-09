### 解题思路
对该题目的样例进行观察，我们可以发现该字符数组有一个特点就是循环性。
我们考虑两种情况。第一种是当所给的target大于或等于字符数组最后一个字符，则返回第一个字符即可。第二种则需要使用二分查找的方法寻找题目要求的字符。于是我们寻找一个转折点，满足左侧的元素小于或等于target，右侧元素必大于target即可。

### 代码

```java
class Solution {
    public char nextGreatestLetter(char[] letters, char target) {
        int length = letters.length;
        if(target >= letters[length - 1]){
            return letters[0];
        }
        int left = 0;
        int right = length - 1;
        while(left < right){
            int mid = (left + right) >>> 1;
            if(target < letters[mid]){
                right = mid;
            }
            else{
                left = mid + 1;
            }
        }
        return letters[left];
    }
}
```
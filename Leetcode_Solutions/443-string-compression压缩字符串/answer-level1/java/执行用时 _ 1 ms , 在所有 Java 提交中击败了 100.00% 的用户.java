### 解题思路
三个变量，其中两个用来移动寻找一个字母出现的起始位置，另一个表示压缩进度。
i 指向字母的开始位置，j 不断寻找与 i 所表示的字母不同的位置，
遍历过程中要注意 j 可能会增加到数组末尾，如数组 ['a','a']，所以当遇到以下两种情况时就可以进行压缩：
1. j == chars.length;
2. chars[i] != chars[j];
找到后 count = j-i 就是该字母出现的次数:
- 若等于 1 ，则不用在压缩的数组中添加次数 1
- 大于 1 时需要添加次数，但是由于一个位置只能放一个小于 10 的数字，因此需要判断次数的数量级。
### 代码

```java
class Solution {
    public int compress(char[] chars) {
        int i = 0,j = 0,len = 0;
        while(j < chars.length){
            if(chars[i] == chars[j]){
                j++;
            }
            if(j == chars.length || chars[i] != chars[j]){
                int count = j - i;
                chars[len++] = chars[i];
                if(count > 1) {// 出现一次以上才会将次数添加进去
                    int div = 1000;// 确认该字母出现次数的数量级
                    while (count / div == 0) {
                        div /= 10;
                    }
                    while (div > 0) {//不能使用 count 作为结束条件，如果 count = 10，就会出错。
                        chars[len++] = (char) (count / div + '0');
                        count = count % div;
                        div /= 10;
                    }
                }
                i = j;
            }
        }
        return len;
    }
}
```
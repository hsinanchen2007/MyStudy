### 解题思路
官方题解使用哈希表，导致时间效率过低，此题解只使用变量来记录情况，运行效率大大提高，细节见代码。

### 代码

```java
class Solution {
    public int lengthOfLongestSubstringTwoDistinct(String s) {
        //字符串为空时直接返回
        if (s.length() == 0) return 0;
        //记录结果
        int result = 0;
        //记录当前长度
        int current = 0;
        //记录最左边字符的索引
        int left = 0;
        //记录两个不同字符的最大索引
        int one = 0;
        int two = 0;
        //记录两个字符
        char first = ' ';
        char second = ' ';
        //确定确定初始两个字符后的第一个检测字符索引
        int begin = 0;
        //确定两个字符
        first = s.charAt(0);
        one = 0;
        for (int i = 1;i <= s.length()-1;i++){
            if (s.charAt(i) != first) {
                //找到第二个字符，初始化各变量
                second = s.charAt(i);
                two = i;
                begin = i+1;
                result = i+1;
                current = i+1;
                break;
            }else one++;
        }
        //如果字符串只存在一种字符
        if (second == ' ') return s.length();
        //开始循环查找最大值
        for (int i = begin;i <= s.length()-1;i++){
            //相同字符时
            if (s.charAt(i) == first) {
                one = i;
                current++;
            }else if (s.charAt(i) == second){
                two = i;
                current++;
            //不同字符时，去除当前最大索引较小的字符
            }else{
                if (one > two){
                    second = s.charAt(i);
                    //当前长度减去删掉的长度
                    current -= (two-left);
                    //重新定左边界
                    left = two + 1;
                    two = i;
                }else {
                    first = s.charAt(i);
                    current -= (one-left);
                    left = one + 1;
                    one = i;
                }
            }
            if (current > result) result = current;
        }
        return result;
    }
}
```
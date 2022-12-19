### 解题思路
定义一个监测回文的函数，从字符数组两端开始比较，逐渐向内收缩，如果不相等则跳出循环返回false，否则是回文返回true。
使用第一个循环控制检查字符数组的大小，从大减小直到为1；（如果是求最小的，则更改为从1递增，按理可以）
使用第二个循环负责用该步长大小的数组遍历最初输入的字符数组，当检测通过时，则为最长回文字符串。
### 代码

```java
class Solution {
    public static String longestPalindrome(String s) {
        int slength = s.length();
        char[] chars = s.toCharArray();
        int start=0;
        // 第一个循环控制监测步长
        for (int i=slength;i>0;i--){
            // 第二个循环负责用每个步长遍历字符数组
            for (int j = 0;j <=slength -i;j++){
                if (isPalindrome(chars,j,j+i-1)){
                    start = j;
                    return String.copyValueOf(chars,start,i);
                }
            }
        }
        return "";
    }
    // 监测回文函数
    static boolean isPalindrome(char[] chars,int s,int e){
        int start = s;
        int end = e;
        while (start<=end){
            if (chars[start] != chars[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
}
```
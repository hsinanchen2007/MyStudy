### 解题思路

**主要思想是借鉴了快速排序的双轴排序方法，通过不断移动两边指针完成最快的反转
**
### 代码

```java
class Solution {
       /**
     * 定义元音常量数组
     */
    static final char[] vowels= {'a','e','i','o','u','A','E','I','O','U'};

    /**
     * 交换元音字母
     * @param s 目标字符串
     * @return 转换后的字符串
     */
    public static String reverseVowels(String s) {
        char[] arrray = s.toCharArray();
        int i = 0;
        int j = arrray.length-1;
        while (i<j){
            //左边指针比较元音字符
             while (i<j&&!ifVowels(arrray[i])){
                 i++;
             }
             //右边指针比较元音字符
             while (i<j&&!ifVowels(arrray[j])){
                 j--;
            }
             //相等的原因字符不转换，继续移动指针
             if (arrray[i] ==arrray[j]){
                 i++;
                 j--;
             }else {
                 //交换两个元音字母并移动指针，检查目标子串是否还有元音字母
                 swap(arrray,i,j);
                 i++;
                 j--;
             }
        }
        return new String(arrray);
    }

    /**
     * 是否为元音字母
     * @param c 目标字符
     * @return 结果
     */
    public static boolean ifVowels(char c){
        for (char vowel : vowels) {
            if (c == vowel){
                return true;
            }
        }
        return false;
    }

    /**
     * 交换方法
     * @param chars 目标字符数组
     * @param i 交换指针
     * @param j 交换指针
     */
    public static void swap(char[] chars,int i,int j){
        char temp = chars[i];
        chars[i] = chars[j];
        chars[j] = temp;
    }
}
```
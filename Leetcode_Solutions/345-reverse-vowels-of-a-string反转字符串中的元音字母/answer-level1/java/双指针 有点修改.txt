使用双指针（一个从头到尾，一个从尾到头），每一次不在元音集合里的第一个指针+1，第二个指针-1，如果一个遇上则一个停下，另一个继续推进，如果两个都遇上元音则进行交换。
与一般代码不同的地方在于，每一次循环同时进行两端指针的判断，在两端都没有遇上元音字符时，速度将是一般代码的两倍，执行速度大幅提高。
如果有错误的地方，请下方回复告知，谢谢。
一般代码：
```
class Solution {
    private final static HashSet<Character> vowels = new HashSet<>(
    Arrays.asList('a','e','i','o','u','A','E','I','O','U'));
    public String reverseVowels(String s) {
        if(s == null) return null;
        int i = 0, j = s.length() - 1;
        char [] result = new char[s.length()];
        while(i <= j) {
            char ci = s.charAt(i);
            char cj = s.charAt(j);
            if(!vowels.contains(ci))
                result[i++] = ci;
            else if(!vowels.contains(cj))
                result[j--] = cj;
            else {
                result[i++] = cj;
                result[j--] = ci;
            }
        }
        return new String(result);
    }
}
```
修改后代码：
```
class Solution {
    private final static HashSet<Character> vowels = new HashSet<>(
    Arrays.asList('a','e','i','o','u','A','E','I','O','U'));
    public String reverseVowels(String s) {
        if(s == null) return null;
        int i = 0, j = s.length() - 1;
        char [] result = new char[s.length()];
        while(i <= j) {
            int swapFlag = 1;
            char ci = s.charAt(i);
            char cj = s.charAt(j);
            if(!vowels.contains(ci)){
                result[i++] = ci;
                swapFlag = 0;
            }
            if(!vowels.contains(cj)){
                result[j--] = cj;
                swapFlag = 0;
            }
            if(swapFlag == 1) {
                result[i++] = cj;
                result[j--] = ci;
            }
        }
        return new String(result);
    }
}
```
效率对比：
![image.png](https://pic.leetcode-cn.com/a2485bb9df3dfc905085a9ca53f6589cc4e8ad1bce82f50b8520cb58036c2d7c-image.png)

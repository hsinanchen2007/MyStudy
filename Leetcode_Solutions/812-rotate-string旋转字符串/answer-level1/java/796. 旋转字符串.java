/**
 * Project:
 * Author : zhaozhen
 * Email  : 
 * Date   : 2019/10/11
 *
 * 解题思路: A + A 相当于把A的最左边的字符全部移动到了右边的并集 看它是否包含B   (A+A).indexOf(b) > 0
 *
 */
```
 public boolean rotateString(String A, String B) {
    if(A.length() != B.length()) return false;

    if((A + A).indexOf(B) >= 0){
        return true;
    }
    return false;
}
```
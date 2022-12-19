### 解题思路
![微信截图_20200114225819.png](https://pic.leetcode-cn.com/8149f8cba3531da34e6351076a2362d19f9a0cc9cf65d1ca93ea8bf1cf56d09b-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20200114225819.png)

思路就是简单的双指针，然后要主要可能出现左右两种情况。
用`str.toCharArray()`代替`str.charAt()`可以提高执行效率。

### 代码

```java
class Solution {
    public boolean validPalindrome(String s) {
        int i = 0,j = s.length() -1;
        char[] chars = s.toCharArray();
        while(i<j){
            if(chars[i]==chars[j]){
                i++;
                j--;
            }else{
                return isVaild(chars,i+1,j) || isVaild(chars,i,j-1) ;
            }
        }
        return true;
    }

    private boolean isVaild(char[] chars ,int i,int j){
        while(i<j){
            if(chars[i++]!=chars[j--]){
                return false;
            }
        }
        return true;
    }
}
```
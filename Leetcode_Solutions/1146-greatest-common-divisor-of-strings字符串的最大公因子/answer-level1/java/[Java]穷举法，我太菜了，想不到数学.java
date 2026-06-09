### 解题思路
把官方穷举用JAVA写了一遍
check函数是检测最大公因数是否能组成输入的字符串，t：公因数字符串，s：原字符串。最后用了2ms（42.82%），38.9mb（9.01%）我去面壁
ps：果然看c++就是会出错，java对比字符串要用`String.equals()`
我还漏个s，疯狂报错。。。

### 代码

```java
class Solution {
    boolean check(String t, String s){
        int lenx = (int)s.length() / (int)t.length();
        boolean result = false;
        /*
        System.out.println("**********check*********");
        System.out.println("s="+s+"s长度="+s.length());
        System.out.println("t="+t+"t长度="+t.length());
        System.out.println("lenx="+lenx);
        */
        String ans = "";
        for(int i = 1; i <= lenx; ++i)
        {
            ans += t;
            
            if(ans.equals(s)){
                //System.out.println("t");
            result = true;
            }
            //else
            //    System.out.println("f");
            
        }
        //System.out.println("ans="+ans);
        //System.out.println("**********check end*********");
        return result;
    }
    public String gcdOfStrings(String str1, String str2) {
        int len1 = str1.length();
        int len2 = str2.length();
        for(int i = Math.min(len1,len2); i >= 1; --i)
        {
            if(len1 % i == 0 && len2 % i == 0)
            {
                String X = str1.substring(0,i);
                //System.out.println(i+X);
                if(check(X, str1) && check(X, str2))
                return X;
            }
            
        }
        return "";
    }
}
```
思路如图：
![未标题-1.gif](https://pic.leetcode-cn.com/4de195e8b89f16886c66944689b6a59d857485b2a44a77e9f15ec0f69a5bd20b-%E6%9C%AA%E6%A0%87%E9%A2%98-1.gif)

先把原先的字符串s翻转，得到s2，然后拿两个宽度是width的框往字符串s和s2上套，看框里面的字符串是否一样。没找到的话width就递减，然后继续。

需要注意的就是，s2里面截取的范围需要算一下，比如s是abc，s2是cba，取s里面取ab的时候，s2取的是ba，
s.substring(0,2)，s2.substring(1,3)，这个1 = 3(总长) - 0(s截取的开始位置) - 2(框的width)



```
public String longestPalindrome(String s) {
        //如果字符串长度位0或1，那么直接返回它本身
        if(s.length() < 2) return s;
        //默认返回一个字符
        String result = s.substring(0,1);
        String strreverse = "";//用来存翻转后的片段
        String strnow = "";//用来存当前截取的片段
        int width = s.length();//每次取多长
        StringBuilder sb = new StringBuilder(s);
        //s2是s的翻转
        String s2 = sb.reverse().toString();
        int left = 0;//左边界
        int right = s.length();//右边界
        while (true){
            for (left = 0; left + width <= right ; left ++){
                //字符串截取
                strnow = s.substring(left,left + width);
                //翻转后字符串截取
                strreverse = s2.substring(s.length() - left - width,s.length() - left);
                if (strnow.equals(strreverse)){
                    if (result.length() < strnow.length()){
                        result = strnow;
                        return result;
                    }
                }
            }
            if (width > 1) {
                width --;
            }else {
                break;
            }
        }
        return result;
    }
```
另外，我前几次提交是在循环内部用stringbuilder翻转字符串，每次都超时，不在循环里使用stringbuilder就可以了
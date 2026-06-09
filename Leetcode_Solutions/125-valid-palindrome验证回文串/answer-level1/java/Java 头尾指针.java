单独定义一个判断合法字符的方法，也可用库函数。
外层while循环控制是否到达中心点，即结束判断；
内层两个while分别判断从头和从尾的对应合法字符是否相等，如果不等直接跳出循环返回false，如果相等则进行下一步判断。
```
public static boolean isPalindrome(String s) {
        if(s==null || s.length()==0) return true;
        s=s.toLowerCase();
        boolean flag = true;
        int low = 0;
        int high = s.length()-1;
        while(low<high){
            while(low<high && !isValidChar(s.charAt(low))){
                low++;
            }
            while(low<high && !isValidChar(s.charAt(high))){
                high--;
            }
            if(s.charAt(low)!=s.charAt(high)){
                flag = false;
                break;
            }
            low++;
            high--;
        }

        return flag;
    }

    public static boolean isValidChar(char c){
        return (c>='0' && c<='9') || (c>='a' && c<='z');
    }
```

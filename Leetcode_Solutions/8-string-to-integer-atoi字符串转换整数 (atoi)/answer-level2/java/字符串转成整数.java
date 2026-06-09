### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int myAtoi(String str) {
        //去掉字符串前后的空格
        str = str.trim();
        if(str.length()==0)
            return 0;
        int index = 0;
        int flag = 1;
        int num = 0;
        if(str.charAt(0)=='+')
            index++;
        else if(str.charAt(0)=='-'){
            index++;
            flag = -1;
        }
        //Character.isDigit()用来判断是否是数字的
        else if(!Character.isDigit(str.charAt(0)))
            return 0;
        while(index<str.length()&&Character.isDigit(str.charAt(index))){
            int temp = str.charAt(index) - '0';
            if(num>(Integer.MAX_VALUE-temp)/10){
                if(flag==-1)
                    return Integer.MIN_VALUE;
                else
                    return Integer.MAX_VALUE;
            }
            num = num * 10 + temp;
            index++;
        }
        return flag==1?num:-num;

    }
}
```
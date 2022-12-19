```
class Solution {
    public int myAtoi(String str) {
        //先去掉开头的空格字符
        char[] char_string=str.trim().toCharArray();
        //定义一个Long的储存结果的ans
        long ans=0L;
        //case中有一个str是"",排除一下
        if(char_string.length==0)return 0;
        //只有开头是 +,—,数字才能输出非0的结果
        if (char_string[0]=='+'||char_string[0]=='-' ||(char_string[0]<='9'&&char_string[0]>='0')){
            if (char_string[0]=='-'){//如果是‘-’
//                  从'-'后的第一个数字开始计算
                for (int i=1;i<char_string.length;++i){
                    if (char_string[i]<='9' && char_string[i]>='0'){
                        ans=ans*10+char_string[i]-'0';
//                  注意这个判断 必须是ans-1,若是ans>Integer.MAX_VALUE+1就会导致>的右边溢出
                        if (ans-1>Integer.MAX_VALUE )return Integer.MIN_VALUE;
                    }else {
                        break;
                    }
                }
            }else if(char_string[0]=='+'){
                for (int i = 1; i < char_string.length; ++i) {
                    if (char_string[i] <= '9' && char_string[i] >= '0') {
                        ans=ans*10+char_string[i]-'0';
                        if (ans>Integer.MAX_VALUE)return Integer.MAX_VALUE;
                    }else {
                        break;
                    }
                }
            }else{
                for (int i = 0; i < char_string.length; ++i) {
                    if (char_string[i] <= '9' && char_string[i] >= '0') {
                        ans=ans*10+char_string[i]-'0';
                        if (ans>Integer.MAX_VALUE)return Integer.MAX_VALUE;
                    }else {
                        break;
                    }
                }
            }
            if (char_string[0]=='-')return -1*(int)ans;
            return (int)ans;
        }
        return 0;
    }
}
```


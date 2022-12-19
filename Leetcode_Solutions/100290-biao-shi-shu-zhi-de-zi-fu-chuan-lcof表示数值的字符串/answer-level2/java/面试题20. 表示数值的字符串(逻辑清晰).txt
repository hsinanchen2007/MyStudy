### 解题思路
根据题意可知，主要情况为num1.num2(e|E)num3和.num2(e|E)num3。.123=0.123已知
有几点判断法则
1.小数点前面是不能有e|E或者小数点的
2.e|E前面是不能有e|E，且前面一定要有数字。
3.+和-只能出现在num1和num3前面（e|E后面）

### 代码

```java
class Solution {
    public boolean isNumber(String s) {
        if(s==null||s.length()==0)return false;
        char[] str=s.trim().toCharArray();
        boolean num=false;
        boolean eE=false;
        boolean dot=false;
        for(int i=0;i<str.length;i++){
            if(str[i]>='0'&&str[i]<='9'){
                num=true;
            }else if(str[i]=='.'){
                if(dot||eE)
                    return false;
                dot=true;
            }else if(str[i]=='e'||str[i]=='E'){
                if(eE||!num)
                    return false;
                eE=true;
                num=false;
            }else if(str[i]=='+'||str[i]=='-'){
                if(i!=0&&str[i-1]!='e'&&str[i-1]!='E')
                    return false;
            }else{
                return false;
            }
        }
        return num;
    }
}

```
### 解题思路

将括号内的表达式递归处理

### 代码

```java
class Solution {
    public boolean parseBoolExpr(String expression) {
        String exp = expression;
        if(exp.equals("t")) return true;
        if(exp.equals("f")) return false;
        if(exp.length()<=3) return true;
        //获取运算符
        char sign = exp.charAt(0);
        //由于形式必为 sign(exp1,exp2,....) 将括号内内容提取
        exp = exp.substring(2,exp.length()-1);
        //将exp1 exp2...存入list
        List<String> list = new ArrayList<>();
        int index = 0;
        //分解当前表达式
        while(index<exp.length()){
            //符号打头的，用计算左括号数量的方式截取
            if(exp.charAt(index)=='&' || exp.charAt(index)=='|' || exp.charAt(index)=='!'){
                int start = index;
                index += 2;//index+1必为'('
                int left = 1;
                while(left>0){
                    if(exp.charAt(index)=='('){
                        ++left;
                    } else if(exp.charAt(index)==')'){
                        --left;
                    }
                    index++;
                }
                list.add(exp.substring(start,index));
            } else if(exp.charAt(index)=='t' || exp.charAt(index)=='f'){//此为单独的逻辑表达式
                list.add(String.valueOf(exp.charAt(index)));
                index++;
            }
            index++;
        }
        //对list进行递归运算
        if(sign == '&'){
            boolean res = true;
            for(String s : list){
                res = res && parseBoolExpr(s);
            }
            return res;
        } else if(sign == '|'){
            boolean res = false;
            for(String s : list){
                res = res || parseBoolExpr(s);
            }
            return res;
        } else{
            return !parseBoolExpr(list.get(0));
        }
    }
}
```
### 解题思路
1、拆分等式：String[] lr = equation.split（"="）;
2、分割lr[0]、lr[1]的每一项，存入List<Streing> res(方法breakIt());
3、整理系数lhs和rhs,强制转换Integer.parseInt(x),方法(coeff(String x));
4、判断系数为0的情况，左右无限，左无解；
5、return "x="+rhs/lhs;


### 代码

```java
class Solution {
    public String coeff(String x){
        if(x.length()>1 && x.charAt(x.length()-2)>='0' && x.charAt(x.length()-2)<='9'){
            return x.replace("x","");
        }
        return x.replace("x","1");
    }
    public String solveEquation(String equation) {

        int lhs=0;  //左系数
        int rhs=0;  //右系数
        String[] lr = equation.split("=");
        for(String x : breakIt(lr[0])){
            if(x.indexOf("x")>=0){
                lhs+=Integer.parseInt(coeff(x));
            }else{
                rhs-=Integer.parseInt(x);
            }
        }
        for(String x : breakIt(lr[1])){
            if(x.indexOf("x")>=0){
                lhs-=Integer.parseInt(coeff(x));
            }else{
                rhs+=Integer.parseInt(x);
            }
        }
        if(lhs==0){
            if(rhs == 0){
                return "Infinite solutions";
            }
            return "No solution";
        }
        return "x="+rhs/lhs;
    }
    public List<String> breakIt(String s){
        List<String> res = new ArrayList<String>();
        String x="";
        for(int i = 0 ; i<s.length() ; i++){
            if(s.charAt(i)=='+' || s.charAt(i) == '-'){
                if(x.length()>0){
                    res.add(x);
                }
                x=""+s.charAt(i);
            }else{
                x+=s.charAt(i);
            }
        }
        res.add(x);
        return res;
    }
}
```
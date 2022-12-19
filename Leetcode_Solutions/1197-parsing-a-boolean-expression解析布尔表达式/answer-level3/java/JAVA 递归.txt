题目不难，就是繁琐了点，得细心。


```
 public boolean parseBoolExpr(String expression) {

        return  f(expression);

    }

    boolean f(String exp){

        char c=exp.charAt(0); //先判断第一个字符
     //如果第一个字符是！，肯定是!(表达式)形的，我们截取字符串并递归
      if (c=='!')return !f(exp.substring(2,exp.length()-1));
      //将 !(表达式) 变为 表达式 并递归处理
      if (c=='&'||c=='|'){
          //把&(expr1,expr2,...)变为expr1,expr2,...
          exp=exp.substring(2,exp.length()-1);
          int i=0;
          List<Boolean>list=new ArrayList<>();//存递归的结果
          while (i<exp.length()){

              if (exp.charAt(i)=='t'||exp.charAt(i)=='f')
              {   //处理t,f,t,f...这种情况
                  list.add(exp.charAt(i)=='t'); i+=2;
              }else {
                  //处理expr1,expr2,... 
                  //expr肯定是带有括号的 比如&(...)b是平衡因子，r初始指向 (后面一个字符
                  int b=1, r=i+2; 
                  while (r<exp.length()&&b!=0)
                  {if (exp.charAt(r)=='(')b++;
                  else  if (exp.charAt(r)==')')b--;r++;
                  }
                  //r指向平衡右括号处
                  //递归处理表达式 处理expri
                  list.add(f(exp.substring(i,r)));
                //指向下一个表达式第一个字符
                  i=r+1;
              }
          }
          Boolean ans=null;
          for (Boolean b:list){
              if (ans==null)ans=b;
              if (c=='&')ans&=b;
              else  ans|=b;
          }
          return  ans;
      }
      //表达式是单纯的t  f
      return  c=='t';

    }

```

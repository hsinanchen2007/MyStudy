### 解题思路
递归做的
感觉比较好理解吧
### 代码

```java
class Solution {
    public boolean parseBoolExpr(String expression) {
        return work(expression.replace(",",""));//发现逗号没啥用就去掉了
    }
    private boolean work(String s){
        //这两个是递归停止条件
        if (s.length()==1 && s.charAt(0)=='t')
            return true;
        if (s.length()==1 && s.charAt(0)=='f')
            return false;
        //如果不满足停止条件，说明字段长度肯定大于1，也就是说有复合运算，那么第一位一定是运算符号
        char operation=s.charAt(0);
        //这里把运算符号运算的内容提取出来
        s=s.substring(2,s.length()-1);
        //栈用来记录是否有一个完整的sub-复合运算
        Stack<Character> stack=new Stack<>();
        //list存储还需要计算的每一个分部分
        List<String> list=new ArrayList<>();
        int left=0,right=0;
        for (int i=0;i<s.length();i++){
            //找到的下一步的某一个复合运算的开始
            if (s.charAt(i)=='!' ||s.charAt(i)=='&' ||s.charAt(i)=='|'){
                stack.push(s.charAt(i));
                if (stack.size()==0)
                    left=i;
            }
            //找到的下一步的某一个复合运算的结尾
            else if (s.charAt(i)==')'){
                stack.pop();
                if (stack.size()==0) {
                    right = i+1;
                    list.add(s.substring(left,right));
                    left=i+1;
                }
            }
            //非复合运算，直接运算t和f
            else if (stack.size()==0 && (s.charAt(i)=='t' || s.charAt(i)=='f')) {
                list.add(String.valueOf(s.charAt(i)));
                left=i+1;
                right=i+1;
            }
        }
        //递归，分别计算list每一个的值，再根据最开始记录的operation运算
        if (operation=='|'){
            boolean res=work(list.get(0));
            for (int i=1;i<list.size();i++){
                res=res||work(list.get(i));
            }
            return res;
        }
        else if (operation=='&'){
            boolean res=work(list.get(0));
            for (int i=1;i<list.size();i++){
                res=res&&work(list.get(i));
            }
            return res;
        }
        //对于非运算，只会有一个值，直接返回即可
        else{
            return !work(list.get(0));
        }
    }
}
```
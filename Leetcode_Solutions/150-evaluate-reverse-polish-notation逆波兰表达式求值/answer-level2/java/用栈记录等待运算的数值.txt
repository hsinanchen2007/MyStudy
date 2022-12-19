执行结果：
通过
显示详情
执行用时 :
17 ms
, 在所有 Java 提交中击败了
52.30%
的用户
内存消耗 :
38.8 MB
, 在所有 Java 提交中击败了
28.16%
的用户
```
class Solution {
    public int evalRPN(String[] tokens) {
        Set<String> sign = new HashSet<String>();
        sign.add("+");
         sign.add("-");
         sign.add("*");
         sign.add("/");
        int len = tokens.length;
        if(len==0)return 0;
        Stack<Integer> sta = new Stack<>();
        for(int i=0; i<len; i++){
            String temp = tokens[i];
            if(!sign.contains(temp)){
                sta.push(Integer.parseInt(temp));
            }else{
                int i1 = (sta.pop());
                int i2 = (sta.pop());
                sta.push(calc(i2,i1,temp));
            }
        }
        return sta.pop();
    }
    private int calc(int i1,int i2, String sign){
        switch (sign){
            case "+" :
                return i1+i2;
            case "-" :
                return i1-i2;
            case "*" :
                return i1*i2;
            case "/" :
                return i1/i2;
        }
        return 0;
    }
}
```

### 解题思路
虽然超级简单无脑，但是自己写出来的感觉就是不一样，速度内存都是百分之5的击败，笑傲江湖


原理很简单，n== 3的时候，就是除了第一个和最后一个是确定的，分别是'(' 和 ')',中就只有4个括号需要组合排列去列出所有可能的组合，是C(4,2)的一个复杂度，就是6中情况
同理 n==4的时候，就是除了第一个和最后一个是确定的，分别是'(' 和 ')',中就只有6个括号需要组合排列去列出所有可能的组合，是C(6,2)的一个复杂度，就是20中情况
以此类推，但是注意，并不是所有的排列都是可以用的，所以还有一个函数负责字符串的合法性
### 代码

```java
class Solution {
    int M = 0;
    int N = 0;
    int[] a ;
    int[] b;
    public List<String> generateParenthesis(int n) {
        ArrayList<String> result = new ArrayList<>();
        N = 2*n-2; 
        M = n-1;
        if(n==1){ // 1
            result.add("()");
            return result;
        }
        if(n==2){  //  2 ，都是我们直接列举出来就行了不需要动脑子
            result.add("()()");
            result.add("(())");
            return result;
        }
         b = new int[n-1]; //
         a = generate(2*n-2);
       
        ArrayList<String> possible = new ArrayList<>();
        combine(2*n-2,n-1,possible); //这个地方比较重要的是，递归里面不要写return ArrayList<String> list;的这种表达，直接导致了退出，根本没有改变possible
       
        for(int i = 0;i<possible.size();i++){
            String p = turn(possible.get(i));  //根据排列组合，把对应的数字下标变成‘（’和 ')'的组合字符串并返回
           
                String temp= "("+p +")";  //加上第一个和最后一个括号
                 if(isOK(temp)){  //做一个字符串是否符合正则表达式的判断
                result.add(temp);
                 }
        }
        return result;
    }
    public int[] generate(int n){  //产生对应的需要排列的数字，例如n==3的时候是 【1，2，3，4】
        int[] result = new int[n];
        for(int i = 0;i<n;i++){
            result[i] = i+1;
        }
        return result;
    }

    public String turn(String str){  //当N == 3的时候，possible arrayList里面的元素分别是，”1 2“，”1 3“，”1 4“，”2 3”，“2 4”，“3 4”,注意这里中间要空格空开，因为当N==6的时候会出现两位数
        String[] duel = str.split(" "); //去掉空格，获得我们要的数字
        
        
        char[] origin = new char[N];
        for(int i =0;i<N;i++){ //先全部变成(((((((
            origin[i] = '(';
        }
        for(int j= 0;j<duel.length;j++){//根据我们取得的duel 字符串数组来，把对应数字下标的元素变成')'
           int num = Integer.parseInt(duel[j]);
            origin[num-1] = ')';
        }
        String res = "";
        for(int i = 0;i<origin.length;i++){
            res += origin[i];
        }
        return res;
    }

    public boolean isOK(String str){  //判断左右括号是否闭合，很简单，不需要解释  
        char[] strAry = str.toCharArray();
        boolean flag = true;
        int sum = 0;
        for(int i = 0;i<strAry.length;i++){
            if(strAry[i] == '('){
                sum+=1;
            }else if(strAry[i] == ')'){
                sum-=1;
            }
            if(sum<0) {
                flag = false;
                break;
            }
        }
        return flag;
    }

  public void combine(int m,int n,ArrayList<String> res){ //最最精华的地方就是排列组合啦，从m个中选出n个， 把结果集放入到 res中
        int i,j;
       
        for(i=n;i<=m;i++) {
            b[n-1] = i-1;
           
            if(n>1)
                combine(i-1,n-1,res);
            else {
                String  s = "";
                for(j=0;j<M;j++){
                    s += a[b[j]] + " ";
                }
                res.add(s);
            }
        }
    }
}
```
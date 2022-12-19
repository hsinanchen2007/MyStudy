
### 思路
将问题思考为： 有 n 个左括号,n 个右括号要放入 String ，求出所有的合法 String 。
我知道代码有冗余，写的时候感觉这样考虑全面些，通过了就懒得优化了。
```java
class Solution {
    //存放结果
    List<String> list = new ArrayList<>();
    public List<String> generateParenthesis(int n) {
        if(n<1) return list;
        //要放n个左括号，n个右括号
        helper("",n,n);
        return list;
    }
    //
    public void helper(String s,int left,int right){
        //此时左右括号都放完，返回结果
        if(left<1&&right<1){
            list.add(s);
            return;
        } 
        //右括号放完，只能放左括号
        if(left>0&&right<1){
            s=s+"(";
            left--;
            helper(s,left,right);
        }else if(left<1&&right>0){//只能放右括号
            s=s+")";
            right--;
            helper(s,left,right);
        }else{//此时左右括号都有剩余，保证左括号剩的比右括号少时才能放右括号
            left--;
            helper(s+"(",left,right);
            if(left+1<right){
                right--;
                helper(s+")",left+1,right);
            }
        }
    }
}
```
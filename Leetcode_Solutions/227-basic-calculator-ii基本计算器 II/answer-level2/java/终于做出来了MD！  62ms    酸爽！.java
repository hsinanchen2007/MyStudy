![捕获.PNG](https://pic.leetcode-cn.com/a6e6884198758a9526bbc0e5b14c5e03c74acaa2e7fac20ca9e60a95d1fc5d56-%E6%8D%95%E8%8E%B7.PNG)
```
class Solution {//33ms
    public int calculate(String s) {
        s=reBuild(s);
        return calculate(s,true);
    }
    private String reBuild(String s){
    String strs[]=s.split(" ");
    return String.join("",strs);
}
    private int calculate(String s,boolean flag){
        int val=0;
        if(flag){
            String strs[]=s.split("\\+");
            for(String str:strs){
                val+=calculate(str,false);
            }
            return val;
        }
        else{
            if(s.charAt(0)=='-')s="0"+s;
            String strs[]=s.split("-");
            val=compute(strs[0]);
            for(int i=1;i<strs.length;i++){
                val-=compute(strs[i]);
            }
            return val;
        }
        
    }
    private int compute(String s){
        
        int index=findLastOperator(s);
        if(index==-1)return Integer.parseInt(s);
        //System.out.println(s);
        int right=Integer.parseInt(s.substring(index+1,s.length()));
        
        if(s.charAt(index)=='*')return compute(s.substring(0,index))*right;
        else return compute(s.substring(0,index))/right;
    }
    private int findLastOperator(String s){//1+3+1*2

        int x=s.lastIndexOf('*');
        int y=s.lastIndexOf('/');
        if(x==-1)return y;
        if(y==-1)return x;
        else return Math.max(x,y);
        
    }
}

```

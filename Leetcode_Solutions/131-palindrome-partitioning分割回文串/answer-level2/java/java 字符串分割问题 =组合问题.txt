### 解题思路
    ## 字符串分割问题一般都是组合问题 长度为n的字符串分割问题=n-1个数的组合问题
     - abc ->a1b2c
     - abc ->a bc  =[1]
     - abc ->a b c =[1,2]
     - abc ->ab c  =[2]
     - abc ->abc   =[]
    
    ##组合、排列问题 用回溯算法来做
    注意：递归结束条件，开始的index=s的长度，本题要求的是一个字符串分割成多个回文串，并且每个串拼接成为原串
 
### 代码

```java
class Solution {
    public List<List<String>> partition(String s) {
       List<List<String>> result = new LinkedList<>();
        if(s==null || s.length()==0){
            return result;
        }
        
        LinkedList<String> path =new LinkedList<>();
        
        backtrack(0,path,s,result);
         
        return result;
    }
    public void backtrack(int first,
                         LinkedList<String>path,
                         String s,
                         List<List<String>> result){
        //一次分割结束时
        if(first==s.length()){
            result.add(new LinkedList<>(path));
            return ;
        }
        
        for(int i=first;i<s.length();i++){
            String sub= s.substring(first,i+1);
            //如果分割出来的串不是回文串，下标右移一位
            if(!isvaild(sub))  continue;
            //选择路径
            path.offer(sub);
            backtrack(i+1,path,s,result);
            path.removeLast();
        }
    }

    public boolean isvaild(String str){      
        int i,j;     
        for(i=0,j=str.length()-1;i<j;i++,j--){     
            if(str.charAt(i)!=str.charAt(j)){
                return false;
            }
        }      
        return true;
    }
}
```
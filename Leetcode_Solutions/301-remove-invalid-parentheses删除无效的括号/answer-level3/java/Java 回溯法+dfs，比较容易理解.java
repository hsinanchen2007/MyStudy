### 解题思路

### 代码

```java
class Solution {
    public List<String> removeInvalidParentheses(String s) {
        List<String> list = new ArrayList<String>();
        if(s==null) return list;
        if(s.equals("")){
            list.add("");
            return list;
        }
        //首先求出要去除左右括号的数目，采用提示中的方法
        int left = 0;
        int right = 0;
        for(int i=0;i<s.length();i++){
            char ch = s.charAt(i);
            if(ch=='('){
                left++;
            }else if(ch==')'){
                if(left>0){
                    left--;
                }else{
                    right++;
                }
            }
        }
        dfs(s,0,left,right,"",list);
        return list;
    }

    /*
    * index代表在原字符串中的下标
    * left代表左括号不匹配的个数
    * right代表右括号不匹配的个数
    * brackets代表目前删除部分括号后的字符串
    */
    public void dfs(String s, int index, int left, int right, String brackets, List<String> list){
        if(left<0 || right<0) return;
        if(index==s.length() ){//到达末尾，判断是否可以加入list中
            if((left!=0 || right!=0)) return;
            if(isValid(brackets) && !list.contains(brackets)){
                list.add(brackets);
            }
            return;
        }
        char ch = s.charAt(index);
        if(ch=='('){
            dfs(s,index+1,left-1,right,brackets,list);//删了左括号
            dfs(s,index+1,left,right,brackets+ch,list);//不删左括号
        }else if(ch==')'){
            dfs(s,index+1,left,right-1,brackets,list);//删了右括号
            dfs(s,index+1,left,right,brackets+ch,list);//不删右括号
        }else{//其他字符,直接加上就行
            dfs(s,index+1,left,right,brackets+ch,list);
        }
    }

    //判断求出的字符串是否合法，这里采用提示中的方法
    public boolean isValid(String s){
        if(s.equals("")) return true;
        if(s.charAt(0)==')') return false;
        int left = 0;
        int right = 0;
        for(int i=0;i<s.length();i++){
            char ch = s.charAt(i);
            if(ch=='('){
                left++;
            }else if(ch==')'){
                if(left>0){
                    left--;
                }else{
                    right++;
                }
            }
            if(right>0) return false;
        }
        if(left!=0) return false;
        return true;
    }

}
```
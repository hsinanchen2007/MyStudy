### 解题思路
采用dfs，bfs，dp三种方法完成
dfs：只需要递归O(n^2)
bfs：需要自己构建节点结构和队列
dp:主要是构建状态方程比较麻烦


### DFS
主要注意的点：可以采用减法也可以采用加法，减法是指还剩多少没用，加法是指已经用了多少。
用减法注意的点是左边必须小于等于右边，就是右括号没用的比较多或者和左括号没用的一样多。

```java
class Solution {
    public List<String> generateParenthesis(int n) {
        List<String> res=new ArrayList<>();
        if(n==0)return res;
        dfs("",n,n,res);
        return res;
    }
    private void dfs(String str,int left,int right,List<String> res){
        if(left==0&&right==0){
            res.add(str);
            return;
        }
        if(left>right)return;
        if(left>0)dfs(str+'(',left-1,right,res);
        if(right>0)dfs(str+')',left,right-1,res);
    }
}
```
### BFS
自己构建节点结构，包含属性：当前字符串，没用的左括号，没用的右括号数，其中退出循环条件就是队列为空，记得第一个元素要先进队
在循环中如果左右括号都用完了就加字符串入res中。
```
class Solution {
    class Node{
        private String str;
        private int left;
        private int right;
        public Node(String str,int left,int right){
            this.str=str;
            this.left=left;
            this.right=right;
        }
    }
    public List<String> generateParenthesis(int n) {
        List<String> res=new ArrayList<>();
        if(n==0)return res;
        Queue<Node> queue=new LinkedList<>();
        queue.offer(new Node("",n,n));
        while(!queue.isEmpty()){
            Node cur=queue.poll();
            if(cur.right==0&&cur.left==0){
                res.add(cur.str);
            }
            if(cur.left>0){
                queue.offer(new Node(cur.str+"(",cur.left-1,cur.right));
            }
            if(cur.right>0&&cur.right>cur.left){
                queue.offer(new Node(cur.str+")",cur.left,cur.right-1));
            }
        }
        return res;
    }
}
```
### 动态规划
从上往下分析，从下往上实现，具体注释有写
```
class Solution {
    public List<String> generateParenthesis(int n) {
        List<String> res=new ArrayList<>();
        if(n==0)return res;
        List<List<String>> dp=new ArrayList<>();//相当于dp[]，用List套List来表示n状态下的结果，结果又是由多种字符串结果组成的
        List<String> dp0=new ArrayList<>();
        dp0.add("");
        dp.add(dp0);//初始化n=0的情况，必须的
        for(int i=1;i<=n;i++){
            List<String> cur=new ArrayList<>();//n=i时候的结果List
            for(int j=0;j<i;j++){
                List<String> str1=dp.get(j);//表示状态转移方程中可能的结果
                List<String> str2=dp.get(i-1-j);//表示状态转移方程中可能剩余的结果
                for(String s1:str1)//List中循环取出字符串
                  for(String s2:str2)
                      cur.add("("+s1+")"+s2);//组成结果插入cur中
            }
            dp.add(cur);
        }
        return dp.get(n);
    }
}
```


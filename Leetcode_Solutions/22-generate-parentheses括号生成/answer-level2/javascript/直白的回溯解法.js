回溯法直接告诉我要用递归，首先想到的八皇后、非菠萝树[斐波那契，这个念着贼拗口]，解题就是凭着大体思路敲代码，然后调试

回溯法列出所有当前状态后的下一个状态，判断最终str是否符合,这个很容易想到使用栈
```
var generateParenthesis = function(n) {
        var result=[]
        if (n<=0) {
            return result
        }
        recursion(0,2*n,result,'')
        return result
    };

    //定义参数，i层次，n截止，a最终结果，str每一层的字符串
    function recursion(i,n,a,str){
        if (i==n) {
            if (isElegal(str)) {
                a.push(str)
            }
            return
        }
        // var temp=i
        recursion(i+1,n,a,str+'(')//无论是i+1，还是i++都会有问题
        recursion(i+1,n,a,str+')')
    }
    
    function isElegal(str){
        var s=[]
        for (let i = 0; i < str.length; i++) {
            const e = str[i];
            if (e==')') {
                if (s[s.length-1]=='(') {
                    s.pop()
                    continue//再继续，写成了break，一时懵逼了
                }
            }
            s.push(e)
        }
        return s.length==0
    }
    console.log(generateParenthesis(1))
```

如果不提示回朔法，没有经验第一感觉就是想通过for循环去造出所有字符串

马踏棋盘意示代码：
```
 var arc=[[2,1],[1,2],[-1,2],[-2,1],[-2,-1],[-1,-2],[1,-2],[2,-1]]

   function recursion(grid,x,y,count){
    for (let i = 0; i < arc.length; i++) {
        const e = arc[i];
        //判断是否受限
        grid[x+arc[0]][y+arc[1]]=count+1
        recursion(grid,x+arc[0],y+arc[1],count+1)
        
    }
   }
```

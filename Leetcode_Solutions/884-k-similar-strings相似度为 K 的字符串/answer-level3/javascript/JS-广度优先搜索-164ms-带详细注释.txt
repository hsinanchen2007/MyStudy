```javascript
var kSimilarity = function(A, B) {
    //起始节点以及步数（初始步数为0）
    let stack=[[A,0]];
    //记录已经访问的节点
    let visited=new Set();
    //将起始节点设置为已访问
    visited.add(A);
    //广度优先搜索
    while(stack.length>0){
        let [now,step] = stack.shift();
        //判断是否达到目标节点
        if(now===B)return step;
        let i=0;
        //忽略掉A与B已经相同的一截
        for(;i<now.length;i++){
            if(now[i]!=B[i])break;
        }
        //now中找到now[j]与B[i]相同的位置j，并且now[j]与B[j]不相同的时候，交换i,j的字符，
        //将其设置为下一个节点,若now[j]与B[j]相同，则交换之后虽说构造了一个位置相同的，
        //但是同时也会拆散一个位置相同的，因此可以将其跳过
        for(let j=i+1;j<now.length;j++){
            if(now[j]===B[i] && now[j]!=B[j]){
                let next = swap(now,i,j);
                if(!visited.has(next)){
                    visited.add(next);
                    stack.push([next,step+1]);
                }
            }
        }
    }
    //用以交换str中的i、j位置的字符，并将结果返回
    function swap(str,i,j){
        return str.substring(0,i)+
               str[j]+
               str.substring(i+1,j)+
               str[i]+
               str.substring(j+1);
    }
};
```
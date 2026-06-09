```
//转为ax=sum；统计a的值以及sum的值
var solveEquation = function(equation) {
    var x=0,
        sum=0,
        cf=0,
        num='';
    for(var i=0;i<equation.length;i++){
                if(equation[i]==='x'){
                    if(num=='+'||num==='-'||num===''){
                        num+='1';
                        if(cf===0)
                            x+=parseInt(num);
                        else
                            x-=parseInt(num);
                        num='';
                    }else{
                        if(cf===0)
                            x+=parseInt(num);
                        else
                            x-=parseInt(num);
                        num='';
                    }
                    continue;
                }
                if(i==equation.length-1||equation[i]==='='||equation[i]==='+'||equation[i]==='-'){
                    if(equation.length-1===i)
                        num+=equation[i];
                    if(num!==''){
                        if(cf===0)
                            sum-=parseInt(num);
                        else
                            sum+=parseInt(num);
                        num='';
                    }
                    if(equation[i]==='='){
                            cf=1;
                            continue;
                        }
                }
        num+=equation[i];
        }
    if(x===0&&sum===0){
        return "Infinite solutions";
    }
    if(x===0&&sum!==0){
        return "No solution";
    }
    return `x=${sum/x}`;
};
```
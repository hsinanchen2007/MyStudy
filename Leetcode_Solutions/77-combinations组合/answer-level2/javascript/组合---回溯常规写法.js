```
var combine = function(n, k) {
        if(n<k) return;
        let arr=[];
        let temp=[];
        let pos=1;
        function helper(arr,temp,pos){
            if(temp.length===k) arr.push(JSON.parse(JSON.stringify(temp)));
            for(let i=pos;i<=n&&temp.length<k;i++){
                temp.push(i);
                helper(arr,temp,i+1)
            }
            temp.pop();
        }
        helper(arr,temp,pos);
        return arr;
    };
```
1.走流程
2.需要记录位置
3.for循环里面需要加一个限制条件
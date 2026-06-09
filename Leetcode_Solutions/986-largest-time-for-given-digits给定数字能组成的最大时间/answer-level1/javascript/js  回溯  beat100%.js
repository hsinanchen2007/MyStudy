```
var largestTimeFromDigits = function(A) {
    //小时位  0-2   分真位置时针为0和1的时候可选0-9，为2的时候选0-3，  秒针第一位 0-5 ，第二位0-9
    let res = new Set();
    let visited = new Array(4).fill(0);
    let temp =[];
    getRes(A,visited,0,temp,res);
    if(res.size==0) return ""
    res= Array.from(res).sort();
    return res[res.length-1];
};

    //回溯
var getRes = function(A,visited,index,temp,res){
    if(index==4){
        res.add(temp.join(""));return;
    }
    for(let i=0;i<A.length;++i){
        if(visited[i]!=1){
                //对时针 和分针,秒针的十位有特殊要求
            let flag = true;
            if(index==0){
                if(A[i]>2) flag=false; 
            }else if(index==1){
                if(temp[0]==2 && A[i]>3) flag=false;
            } else if(index==2){
                if(A[i]>5) flag=false;
            } 
            if(flag){
                visited[i]=1;
                temp.push(A[i]);
                if(index==1) temp.push(":");
                getRes(A,visited,index+1,temp,res);
                visited[i]=0;
                temp.pop();
                if(index==1) temp.pop();
            }
        }
    }
}
```

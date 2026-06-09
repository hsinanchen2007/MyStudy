## 运行情况
![image.png](https://pic.leetcode-cn.com/479104a93899b64ec99813626444577531a21052492e3112e8457f953c78cb2f-image.png)

## 思路
参照[累加数](https://leetcode-cn.com/problems/additive-number/solution/di-gui-ji-bai-100-by-lee-lei/)
需要多加一些判断
- 每个数要小于2^31-1
- 多加一个参数path来保存路径

## 题解
```
var splitIntoFibonacci = function(S) {
    if(S.length<3){
        return false;
    }
    let ans = [];
    const backtrack = function(first,second,rest,path){
        if(first !== "" && second !== ""){
            if((first.length>1&&first[0]==="0")||(second.length>1&&second[0]==="0")){ return;}
            let sum = Number(first)+Number(second);
            if(sum>2**31-1){return;}
            if(rest.indexOf(sum)===0){
                //符合条件，往后推
                rest = rest.substring(String(sum).length)
                path.push(String(sum));
                if(!rest.length){
                    if(!ans.length){
                        ans = path;
                    }
                    return ;
                }
                backtrack(second, sum, rest, path.slice());
            }
            return;
        }
        for(let i=1;i < Math.floor(rest.length/2)+1;i++){
            first = rest.substring(0,i);
            let temp = rest.substring(i);
            let path1 = path.concat([first]);
            for(let j=1;j < Math.floor(temp.length/2)+1;j++){
                second = temp.substring(0,j);
                let temp2 = temp.substring(j);
                backtrack(first,second,temp2,path1.concat([second]));
            }
        }
    }
    backtrack("","",S,[]);
    return ans;
};
```
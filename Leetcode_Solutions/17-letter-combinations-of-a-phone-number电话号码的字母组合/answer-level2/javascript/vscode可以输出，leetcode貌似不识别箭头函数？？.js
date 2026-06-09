虽然这里通不过，但是一定是正确的，各位JS大佬看看

```js
var letterCombinations = function(digits) {
    // 建立map和num两个数组，用来一一对应
    let map=["",1,"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"]
    let num=digits.split("")
    let code=[]
    num.forEach(item=>{
        if(map[item]){
            code.push(map[item])
        }
    })
    let comb=arr=>{
        let tmp=[]
        for(let i=0,il=arr[0].length;i<il;i++){
            for(let j=0,jl=arr[1].length;j<jl;j++){
                tmp.push(`${arr[0][i]}${arr[1][j]}`)
            }
        }
        arr.splice(0,2,tmp)
        if(arr.length>1){
            comb(arr)
        }else{
            console.log(tmp)
            return tmp
        }
        return arr[0]
    }
    return comb(code)
};
letterCombinations("789")
```

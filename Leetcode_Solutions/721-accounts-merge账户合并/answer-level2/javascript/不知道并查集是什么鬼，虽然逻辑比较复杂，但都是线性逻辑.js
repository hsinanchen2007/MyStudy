```
/**
 * @param {string[][]} accounts
 * @return {string[][]}
 */
var accountsMerge = function(accounts) {
    const ans = []
    const personList = []
    for(let i=0;i<accounts.length;i++) personList.push(i)
    //key是email，value是邮箱在accounts中的第一层下标
    const emailPersonMap = new Map()
    //key是personList的i，value是email列表
    const positionMap = new Map()
    //建立email和personList中下标i的关系
    for(let i=0;i<accounts.length;i++){
        for(let j=1;j<accounts[i].length;j++){
            if(emailPersonMap.has(accounts[i][j])){
                union(personList,i,emailPersonMap.get(accounts[i][j]))
            }else emailPersonMap.set(accounts[i][j], i)
        }
    }
    //从emailPersonMap中提取出每一个person的meailList，注意这时personList的值大概率发生了改变
    emailPersonMap.forEach((value, email) => {
        //所以这里要取值，而不能直接用emailPersonMap.get(email)
        const position = personList[emailPersonMap.get(email)]
        if(positionMap.has(position)){
            positionMap.get(position).push(email)
        }else positionMap.set(position,[email])
    })
    //排序emailList，然后补上一个porson名字
    positionMap.forEach((value, key) => {
        value.sort()
        value.unshift(accounts[key][0])
        ans.push(value)
    })
    return ans
};
//相同的人标为相同的值
function union(array,from,to){
    from = array[from]
    to = array[to]
    for(let i=0;i<array.length;i++){
        if(array[i] === from) array[i] = to
    }
}
```

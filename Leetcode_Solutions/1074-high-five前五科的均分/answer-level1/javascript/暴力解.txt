### 解题思路
暴力解法：
1、按学生id对数组进行分类，将同一id里的分数存入一个数组中，用map存结果
2、对map遍历，对每一个key对应的数组排序，取最大的五个数求平均值

### 代码

```javascript
/**
 * @param {number[][]} items
 * @return {number[][]}
 */
var highFive = function(items) {
    let map = new Map()
    for (let i=0;i<items.length;i++){
        let tmp = items[i]
        if(!map[tmp[0]]){
            map[tmp[0]] = [tmp[1]]
        }else{
            map[tmp[0]].push(tmp[1])
        }
    }   // 按学生id分类，每个学生的成绩存在map中
    let res = []
    for(let key in map){
        let tmpArr = map[key].sort((a,b)=> b-a).slice(0,5) // 对学生key的成绩进行排序，并且取最大的五个值
        let sum = tmpArr.reduce((prev,curr) =>{
            return prev+curr
        },0);        // 求和
        res.push([Number(key),Math.floor(sum/5)]);     
    }
    return res
};
```
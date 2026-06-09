#### 解题思路
&emsp;&emsp;并查集思想。用了3给map来实现数据的连接。具体看注释吧，不过就是效率有点低跑了600ms...
#### 代码
```javascript []
var trulyMostPopular = function(names, synonyms) {
    //map 查找对应的并集标记数字, keySet映射查找同名字集合, numsbers用于累加同名人数
    let map = {}, keySet = {}, numsbers = {}, flag = 0;
    let reg = /(\w+)\((\d+)\)/, ret = [];
    for(let i = 0; i < synonyms.length; i++){
        let nameSet = synonyms[i].substring(1, synonyms[i].length - 1).split(',');
        //如果两个名字都不在任何集合当中，那么将这个两个名字做一个集合
        if(!map[nameSet[0]] && !map[nameSet[1]]){
            map[nameSet[0]] = map[nameSet[1]] = flag;
            keySet[flag++] = [nameSet[0], nameSet[1]];
        //如果有一个名字不在集合中另一个在，将不再集合的名字添加到集合中
        }else if(!map[nameSet[1]] && map[nameSet[0]]){
            map[nameSet[1]] = map[nameSet[0]]
            keySet[map[nameSet[0]]].push(nameSet[1]);
        }else if(!map[nameSet[0]] && map[nameSet[1]]){
            map[nameSet[0]] = map[nameSet[1]]
            keySet[map[nameSet[1]]].push(nameSet[0]);
        //如果两个名字都在集合当中，将这个两个集合合并 ([a = b, c = d, a = d]这种情况，将a, b, c, d合并为一个集合)
        }else if(map[nameSet[0]] && map[nameSet[1]]){
            let max = map[nameSet[1]] > map[nameSet[0]] ? map[nameSet[1]] : map[nameSet[0]],
                min = max ^ map[nameSet[1]] ^ map[nameSet[0]];
            keySet[min] = keySet[min].concat(keySet[max]);
            for(let i = 0; i < keySet[max].length; i++){
                map[keySet[max][i]] = min;
            }
        }
    }
    //字典序排序
    for(key in keySet){
        keySet[key].sort();
    }
    //人数累计
    for(let i = 0; i < names.length; i++){
        let [, name, number] = reg.exec(names[i]);
        let index = map[name];
        //无同名直接添加到结果数组
        if(index == undefined){
            ret.push(`${name}(${number})`)
        //同名人数累加
        }else{
            numsbers[index] = numsbers[index] + parseInt(number) || parseInt(number);
        }
    }
    for(key in numsbers){
        ret.push(`${keySet[key][0]}(${numsbers[key]})`);
    }
    return ret;
};
```
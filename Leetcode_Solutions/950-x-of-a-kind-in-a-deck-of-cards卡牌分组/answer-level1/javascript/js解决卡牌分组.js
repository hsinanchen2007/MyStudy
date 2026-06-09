### 解题思路
将卡牌内的数字排序，然后把相同的数字编成一组,然后根据组合里面的每一项的长度，求最大公约数，如何把相同的分组呢，首先想到的是正则，但发现正则只能针对于卡牌的数目是0-9，然鹅测试的时候有10以上，好的over，只能手写分组的方法，数组长度为1需要特殊判断，不为1就判断第一位和第二位是否相等，相等就推入数组，不相等就是一个分组结束的临界点，重新开始下一个分组，二者都需要将推入的元素从arr中删除。另外，得到分组数据后，求最大公约数是根据分组内的数据长度来的。我撸的代码内存消耗蛮高，应该还有优化地方，嘤嘤嘤。

### 代码

```javascript
/**
 * @param {number[]} deck
 * @return {boolean}
 */
var hasGroupsSizeX = function(deck) {
    //将卡牌内的数字排序，然后正则匹配成相同的组合,然后根据组合里面的每一项，求最大公约数
    let arr=deck.sort();
    let str=arr.join('');
    //使用正则 /(\d)\1+|(\d)/代表匹配相同的数字1次及以上
    //let newGroup=str.match(/(\d)\1*/g);
   let newGroup=tidyGroup(arr);
   console.log(newGroup);
    while(newGroup.length>1){
        //这里面我们只关心长度
        let al=newGroup.shift().length;
        let bl=newGroup.shift().length;
        let result=gcd(al,bl);
        //如果是1，那可以直接结束说明不符合要求，如果不是1，那需要继续比较下去，但我们关心的只是长度，所以给他的数组里面放回去一个比较后的长度的字符串就可以了
        if(result===1){
            return false;
        }else{
            newGroup.unshift('1'.repeat(result));
        }
    }
    //最终需要处理边界，我们存放分组的数组需要不为空，并且，分组内容的长度，需要大于1
    return newGroup.length?newGroup[0].length>1:false;
};
//实现找最大公约数的函数
function gcd(a,b){
    if(b===0){
        return a;
    }else{
        return gcd(b,a%b);
    }
}
function tidyGroup(arr){
    let newarr=[];
    let group=[];
    while(arr.length>0){
        if(arr.length===1){
            if(group[0]===arr[0]){
                group.push(arr[0]);
                arr.shift();
                newarr.push(group);
                break;
            }
        }
        if(arr[0]===arr[1]){
            group.push(arr[0]);
            arr.shift();
        } else {
            group.push(arr[0]);
            arr.shift();
            newarr.push(group);
            group=[];
        }
    }

    return newarr;
}

```
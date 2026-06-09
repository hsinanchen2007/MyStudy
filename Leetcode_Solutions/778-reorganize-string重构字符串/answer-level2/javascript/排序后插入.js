## 运行情况
![image.png](https://pic.leetcode-cn.com/37f4385242506e31b0faeaf6f0aeac7309b94869380219814dbfc99ed2a6e41c-image.png)

### 思路
#### 无法构造的情况
- a,a,a,b 偶数
- a,a,a,a,b 基数

总结: 只要有一个数出现的次数大于`Math.ceil(S.length/2)`就无法构造

#### 可以构造的情况
显而易见，最多的数，一定要放在外面的
所以我们先放置好最多的数，假设为`a`
`aaaaaaa`
然后往里面插入其他的数，插完一个，就隔一个再插入，直到把所有的数插完
`ababacadae`
返回答案，完事儿

### 题解

```
var reorganizeString = function(S) {
    let hashArr = new Array(26).fill(0);
    for(let i=0;i<S.length;i++){
        let item = hashArr[S[i].charCodeAt()-97];
        if(item){
            item.count++;
        }else{
            hashArr[S[i].charCodeAt()-97] = {name:S[i],count:1}
        }
    }
    hashArr = hashArr.filter((v)=>v!=0); //把没出现的数字去掉，减少后面遍历次数
    hashArr.sort((a,b)=>(b.count-a.count));
    //以上的处理都是把字符串统计成以下这种格式
    //[{name:"a",count:2},{name:"b",count:1}]
    //hashArr的结构有多种，反正你要能记录每一个数对应出现的次数就好了，然后取出出现频率最高的一个数

    let ans = []
    if(hashArr[0].count>Math.ceil(S.length/2)){
        //这里是无法构造的情况
        return ""
    }else{
        //这里是可以构造的
        for(let i=0;i<hashArr[0].count;i++){
            ans.push(hashArr[0].name);
        }
        let cur = 1;
        let i = 1;
        while(cur < hashArr.length){
            ans.splice(i,0,hashArr[cur].name);
            hashArr[cur].count--;
            if(!hashArr[cur].count){
                cur++;
            }
            //隔一个插入
            i+=2;
            if(i>=ans.length+1){
                //注意：如果是超出一位的话，也是可以的，因为插到最后，就是超出一位
                i=1;
            }

        }
    }
    return ans.join('');
};
```
思路：遍历每一行并统计1的个数，个数大于1，也就是说明这一行的服务器都可以通信，直接在总数上加上这一行的1的个数。
没有1，就不考虑。正好等于1的话，看一下1所在的这一列有没有1，只要有1个1，这一行的单独这个1也算在总数内。
```
var countServers = function(grid) {
    let count = 0;
    grid.forEach((item, index, self) => {
        let tempCount = 0;
        for(let i = 0; i < item.length; i ++) {
            tempCount += item[i] === 1 ? 1 : 0;
        }
        if(tempCount === 1) {
            for(let i = 0; i < item.length; i ++) {
                if(item[i] === 1) {
                    for(let j = 0; j < self.length; j ++) {
                        if(self[j][i] === 1 && j !== index) {
                            count += 1;
                            break;
                        }
                    }
                }
            }
        }else if (tempCount > 1) {
            count += tempCount;
        }
    })
    return count;
};
```

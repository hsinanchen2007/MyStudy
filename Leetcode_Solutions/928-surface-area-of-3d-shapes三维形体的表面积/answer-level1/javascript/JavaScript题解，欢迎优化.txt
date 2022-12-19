### 解题思路
此处撰写解题思路
一个柱体中：2个底面 + 所有的正方体都贡献了4个侧表面积
两个挨着的柱体需要减去较小的那个的双份表面--如2和3相贴，需要减去小的乘2（2*2）

### 代码

```javascript
/**
 * @param {number[][]} grid
 * @return {number}
 */
var surfaceArea = function(grid) {
    function computedValue(arr,beforeArr){
        // 传入两个值进行计算，arr为当前，before为上一份--可以理解为左侧的
        let res = 0
        arr.forEach((item,idx)=>{
            // 判断是否有上一份，有的获取上一份相贴的数组
            let beforeItem = idx>0?arr[idx-1]:0
            // 判断 上一份相贴的表面积
            let beforeArrItem = (beforeArr.length>0?(beforeArr[idx]>item?item:beforeArr[idx]):0)*2
            console.log(beforeItem,beforeArrItem)
            // 总的表面积等于 自己的减去前一份相贴的表面积，和上一份相贴的表面积
            res += (item>0?(item*4+2):item)-((item>beforeItem?beforeItem:item)*2)-beforeArrItem
        })
        console.log(res)
        return res
    }
    let data = 0
    let beforeArr = []
    grid.forEach((item,len)=>{
        data+=len===0?computedValue(item,[]):computedValue(item,grid[len-1])
    })
    return data
};
```
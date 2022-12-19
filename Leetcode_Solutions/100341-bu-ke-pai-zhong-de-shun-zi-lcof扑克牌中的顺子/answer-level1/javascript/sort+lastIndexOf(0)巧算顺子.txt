### 效率
![TIM截图20200316232713.png](https://pic.leetcode-cn.com/91d5f0e25dbc69e7ae9fc1f3d68097cceaf4868c38e525639ed2e17b0a2b1ea6-TIM%E6%88%AA%E5%9B%BE20200316232713.png)

### 解题思路
- lastIndexOf+1获取0的个数且是第一个非0数的坐标
- 从第一个非0数遍历，用后一个减去前一个
- 差值是-1代表有重复的直接返回false
- 否则累加判断间隔多少
- 如果0的数量>=间隔数量 则是顺子

### 代码

```javascript
var isStraight = function(nums) {
    nums.sort((a,b)=>a-b)
    // 0 的个数,第一个非0的坐标
    let zero = nums.lastIndexOf(0)+1
    let count = 0
    let len = nums.length
    for(let i=zero;i<len-1;i++){
        let cut = nums[i+1]-nums[i]-1
        // 这里等于-1代表两个数相等的，那肯定不是顺子
        if(cut == -1){
            return false
        }
        count+=cut
    }
    return zero>=count?true:false
};
```
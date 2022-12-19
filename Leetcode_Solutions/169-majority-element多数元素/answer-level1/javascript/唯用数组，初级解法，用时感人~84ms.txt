`var majorityElement = function(nums) {`
    `// 统计有几个字符`
    `var newStrs=[]`
    `// 统计每个字符的个数`
    `var newNums=[]`
    `// 长度`
    `var l=nums.length/2`
    `// 结果序号`
    `var resultIndex`
    `// 结果数字`
    `var endNum`
    `// 计算有几种字符`
    `for(var j=0; j<nums.length; j++){` 
        `// 没有重复的`
        `if(newStrs.indexOf(nums[j]) == -1){`
            `newStrs.push(nums[j])`
        `}`
    `}`
    `// 计算每个字符的个数`
    `for(var i=0; i<newStrs.length; i++){`
        `var count=0`
        `for(var k=0; k<nums.length; k++){`
            `if(newStrs[i] == nums[k]){`
                `count++`
            `}`
        `}`
        `newNums.push(count)`
    `}`
    `// 找出长度大于l的字符的个数，存储序号`
    `for(var m=0; m<newNums.length; m++){`
        `if(newNums[m]>l){`
            `resultIndex = m`
        `}`
    `}
    `endNum = newStrs[resultIndex]`
    `return endNum`
`};`
唯用数组，初级解法，用时感人~84ms
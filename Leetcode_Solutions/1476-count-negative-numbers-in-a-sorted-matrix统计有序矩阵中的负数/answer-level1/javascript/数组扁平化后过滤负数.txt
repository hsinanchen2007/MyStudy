// 数组扁平化后过滤负数
var countNegatives = function(grid) {
    return grid.toString().split(',').filter(v=>v<0).length
};
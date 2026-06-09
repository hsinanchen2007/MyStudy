/**
 * @param {number[][]} A
 * @return {number[][]}
 */
var flipAndInvertImage = function(A) {
    var result = []
    //水平反转
    var tempArr = A.map(function(item,index){
        return item.reverse()
    })
    result = tempArr.map(item => {
        return item.map(_item => {
            return _item = !_item
        })
    })
    return result
};
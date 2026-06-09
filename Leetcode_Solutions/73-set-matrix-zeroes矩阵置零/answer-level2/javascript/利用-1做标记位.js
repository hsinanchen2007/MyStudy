var setZeroes = function(matrix) {
    for(let i = 0;i < matrix.length;i++){
        for(let j = 0;j < matrix[i].length;j++){
            if(matrix[i][j] == 0){
                matrix[i][-1] = true
                matrix[-1] ? matrix[-1][j] = true : (matrix[-1] = [],matrix[-1][j] = true) 
            }
        }
    }
    for(let i = 0;i < matrix.length;i++){
        for(let j = 0;j < matrix[i].length;j++){
            if((matrix[-1] && matrix[-1][j]) || matrix[i][-1]) {
                matrix[i][j] = 0
            }
        }
    }
    return matrix
};
当然严格意义上来说，空间复杂度为O(m+n) 
其他语言别这样搞，不然把其他地址搞爆了

    /**
    * @param {string} s
    * @param {number} numRows
    * @return {string}
    */

    var convert = function(s, numRows) {
    var array = new Array();
    var i = 0;
    var j = 0; // 行数
    var k = 0; // 列数
    var result = ''; // 存结果
    for( let x = 0; x < numRows; x++){
        array[x] = new Array();
        for(let y = 0; y < s.length; y++){ // 空间浪费，实际不需这么多空间
            array[x][y] = 0;
        }
    }
    if(numRows === 1){
        return s;
    }
    while(i<s.length){ // 遍历字符串s
       if(j === 0){
           while( j!== numRows - 1) {
               array[j][k] = s[i];
               j++;
               i++;
               if(i === s.length) break;    // 到达最高长度，跳出循环
           }
       }
       if(i === s.length) break;    // 到达最高长度，跳出循环
       array[j][k] = s[i];
       j--;
       k++;
       i++;
    }
    for(let x=0; x<numRows; x++){
        for(let y=0; y < s.length; y++){
            if(array[x][y] !== 0 ){
                result = result+array[x][y];
            }
        }
    }
    return result;
};

硬凑出来的...空间浪费了许多，流程也不太清晰，发出来大家轻喷
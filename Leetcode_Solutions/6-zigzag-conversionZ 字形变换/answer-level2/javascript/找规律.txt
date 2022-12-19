var convert = function(s, numRows) {
    if(numRows ===1){
        return s;
    }
    let multiple = (numRows-1)*2;
    let times = parseInt(s.length/multiple);
    let str = ""
    for (let i=0;i<numRows;i++){
        let tmp_str = "";
        for (let j=0;j<=times;j++){
            let now = j*multiple+i;
            let next_el = (j+1)*multiple - i;
            if (i===0){
                tmp_str+=s.charAt(now);
            }else if (i===numRows-1){
                tmp_str+=s.charAt(next_el);
            }else {
                tmp_str+=s.charAt(now)+s.charAt(next_el);

            }

        }
        str+=tmp_str
    }
    return str;
};

这个题找到规律就好了  首先计算出共有几次折叠，即为代码中的times，遍历每行，首行和末行的中的每次折叠只有一个字母，首末中间的有两个字母，所以要分开来看。其次，计算出每次折叠的数量。当前的now 即为当前行的当前折叠的第一个字符，next即为当前行的当前折叠的最后一个字符。
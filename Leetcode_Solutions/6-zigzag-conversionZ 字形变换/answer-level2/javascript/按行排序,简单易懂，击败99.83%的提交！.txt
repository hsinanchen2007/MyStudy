定义一个numRows项数组arr，每一项存变换后的行字符串。遍历s字符串，记录每个字符的下一行，以及Z字形变换排列位置，将字符添加到数组对应项。

var convert = function(s, numRows) {
    let sl = s.length,
        arr = new Array(numRows).fill(''),
        line = 0,
        dir = 0 // 0是从上到下，1是从下到上

    if (numRows === 1) return s

    for (let i = 0; i < sl; i++) {
        arr[line] += s[i]

        if (line === (numRows - 1)) dir = 1
        else if (line === 0) dir = 0

        if (!dir) line++
        else line--
    }
    
    return arr.join('')
};
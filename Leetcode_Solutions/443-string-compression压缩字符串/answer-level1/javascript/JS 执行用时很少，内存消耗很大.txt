`var compress = function(chars) {
    let char = chars[0];
    let num = 0;
    let index = 0;
    let numArr = [];
    chars.forEach(item => {
        if (item === char) {
            num++;
        } else {
            chars[index] = char;
            if (1 < num && num < 10) {
                index++;
                chars[index] = String(num);
            } else if (num >= 10) {
                numArr = String(num).split('');
                numArr.forEach(n => {
                    index++;
                    chars[index] = String(n);
                });
            }
            index++;
            char = item;
            num = 1;
        }
    });
    chars[index] = char;
    if (1 < num && num < 10) {
        index++;
        chars[index] = String(num);
    } else if (num >= 10) {
        numArr = String(num).split('');
        numArr.forEach(n => {
            index++;
            chars[index] = String(n);
        });
    }
    index++;
    chars.length = index;
    return index;
};`
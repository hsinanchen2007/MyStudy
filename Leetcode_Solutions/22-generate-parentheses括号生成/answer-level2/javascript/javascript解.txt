/**
 * @param {number} n
 * @return {string[]}
 */
var generateParenthesis = function(n) {
    function addLeft(item) {
        return {
        left: item.left + 1,
        right: item.right,
        str: item.str + '('
        }
    }

    function addRight(item) {
        return {
        left: item.left,
        right: item.right + 1,
        str: item.str + ')'
        }
    }

    function paddingRight(item) {
        while (item.right < item.left) {
        item.right++;
        item.str += ')';
        }
        return item.str;
    }

    if (n < 1) return [];
    let arr = [{
        left: 1,
        right: 0,
        str: '('
    }];
    let strArr = [];
    let count = 1;
    while (count < n * 2) {
        let len = arr.length;
        for (let i = 0; i < len; i++) {
        const item = arr[i];
        if (item.left === n) {
            strArr.push(paddingRight(item));
            continue;
        }
        if (item.left > item.right) {
            arr.push(addLeft(item));
            arr.push(addRight(item));
        } else {
            arr.push(addLeft(item));
        }
        }
        arr.splice(0, len);
        count++;
    }
    return strArr;
};
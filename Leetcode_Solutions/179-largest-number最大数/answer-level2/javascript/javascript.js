
var largestNumber = function(arr) {
    if (arr.length == 1)
        return arr[0].toString();
    let flag = true;
    arr.sort((a, b) => {
        if (a != 0 || b != 0)
            flag = false;
        return (a.toString() + b.toString()) > (b.toString() + a.toString()) ? -1 : 1;
    })
    if (flag)
        return '0';
    return arr.join("");
}
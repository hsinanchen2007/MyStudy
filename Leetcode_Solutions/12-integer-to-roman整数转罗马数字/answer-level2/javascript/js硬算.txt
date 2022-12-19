var intToRoman = function (num) {
    let str = '';
    let a = 0;
    a = parseInt(num / 1000);
    str += a == 3 ? 'MMM' : a == 2 ? 'MM' : a == 1 ? 'M' : '';
    a = parseInt(num % 1000 / 100);
    str += a == 9 ? 'CM' : '';
    if (a != 9) {
        a = parseInt(num % 1000 / 500);
        str += a == 1 ? 'D' : '';
        a = parseInt(num % 500 / 100);
        str += a == 4 ? 'CD' : a == 3 ? 'CCC' : a == 2 ? 'CC' : a == 1 ? 'C' : '';
    }
    a = parseInt(num % 100 / 10);
    str += a == 9 ? 'XC' : '';
    if (a != 9) {
        a = parseInt(num % 100 / 50);
        str += a == 1 ? 'L' : '';
        a = parseInt(num % 50 / 10);
        str += a == 4 ? 'XL' : a == 3 ? 'XXX' : a == 2 ? 'XX' : a == 1 ? 'X' : '';
    }
    a = parseInt(num % 10 / 1);
    str += a == 9 ? 'IX' : '';
    if (a != 9) {
        a = parseInt(num % 10 / 5);
        str += a == 1 ? 'V' : '';
        a = num % 5;
        str += a == 4 ? 'IV' : a == 3 ? 'III' : a == 2 ? 'II' : a == 1 ? 'I' : '';
    }
    return str;
}
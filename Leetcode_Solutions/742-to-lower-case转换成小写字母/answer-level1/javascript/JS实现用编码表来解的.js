var toLowerCase = function (str) {
    var char;
    for (var i = 0; i < str.length; i++) {
        if (str.charCodeAt(i) <= 90 && str.charAt(i) >= 65) {
            str = str.replace(str.charAt(i), String.fromCharCode(str.charCodeAt(i) + 32));
        }
    }
    return str;
};
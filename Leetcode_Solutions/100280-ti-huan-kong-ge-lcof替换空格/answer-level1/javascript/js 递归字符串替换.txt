/**
 * @param {string} s
 * @return {string}
 */
var replaceSpace = function (s) {
    return s.search(' ') >= 0 ? replaceSpace(s.replace(' ', '%20')) : s;
};
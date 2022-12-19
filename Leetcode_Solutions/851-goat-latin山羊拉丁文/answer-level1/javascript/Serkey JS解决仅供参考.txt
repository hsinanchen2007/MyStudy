/**
 * @param {string} S
 * @return {string}
 */
var toGoatLatin = function(S) {
    let a = S.split(' ');
    let n = a.map((e, i) => {
        let suffix = new Array(i + 1).fill('a');
        if ('aeiouAEIOU'.indexOf(e[0]) > -1) {
            return e + 'ma' + suffix.join('');
        } else {
            return e.slice(1) + e[0] + 'ma' + suffix.join('');
        }
    });
    return n.join(' ');
};
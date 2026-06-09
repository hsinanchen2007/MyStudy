```
/**
 * @param {string} s
 * @return {boolean}
 */
var checkRecord = function(s) {
    let reg = /A/g;
    if(s.match(reg) && s.match(reg).length > 1) {
        return false;
    }
    reg = /L{3,}/
    if(reg.test(s)) {
        return false;
    }
    return true;
};
```

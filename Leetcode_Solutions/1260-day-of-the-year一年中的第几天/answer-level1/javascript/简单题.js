```javascript
/**
 * @param {string} date
 * @return {number}
 */
var dayOfYear = function(date) {
    let dates = date.split('-');
    const year = parseInt(dates[0]);
    let hash = {
        '01': 0,
        '02': 31,
        '03': 59,
        '04': 90,
        '05': 120,
        '06': 151,
        '07': 181,
        '08': 212,
        '09': 243,
        '10': 273,
        '11': 304,
        '12': 334
    }
    
    let isLeep = !(year % 4) && !!(year % 100) || !(year % 400)
    
    return hash[dates[1]] + parseInt(dates[2]) + ((isLeep && parseInt(dates[1]) > 2) ? 1 : 0)
};
```
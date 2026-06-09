```
/**
 * @param {number[]} data
 * @return {boolean}
 */
var validUtf8 = function(data) {
    let flag = 0
    for(let i=0;i < data.length;i++) {
        let item = data[i].toString(2)
        const length = item.length
        for(let j = 8 - length;j > 0;j--) item = '0' + item
        if(item[0] === '0') {
            if(flag === 0) continue
            else return false
        }else{
            if(flag === 0) {
                while((flag < 8) && (item[++flag] === '1')) ;
                if(flag === 8) return false
                flag--
                if((flag < 1) || (flag > 3)) return false
            }else {
                if(item.substring(0, 2) !== '10') return false
                flag--
            }
        }
    }
    return flag > 0? false : true
};
```

![Snipaste_2020-03-22_21-22-44.jpg](https://pic.leetcode-cn.com/643b882d48e981eb5eab15418b8521765b9f766e8ad7e08f048c27a808ef9396-Snipaste_2020-03-22_21-22-44.jpg)
```
var isAdditiveNumber = function(num) {
    const isValid = (s1, s2, num) => {
        if(num.length <= 0) return true;
        let cur = `${+s1 + +s2}`;
        if (`${num}`.startsWith(cur)) {
            return isValid(s2, cur, num.substr(cur.length))            
        }
    }
    let len = num.length;
    for(let i =1; i < len; i++) {
        let s1 = num.substr(0, i);
        if((s1[0] == 0) && i >1) return false
        for (let j = 1; j < len; j++) {
            if(Math.max(i,j) > (len-i-j)) {
                break;
            }
            let s2 = num.substr(i, j);
            if((s2[0] == 0) && j > 1) {
                break;
            }
            if (isValid(s1, s2, num.substr(i+j))){
                return true;
            }
        }
    }
    return false
};
```
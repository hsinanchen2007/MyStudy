```
/**
 * @param {string} a
 * @param {string} b
 * @return {string}
 */
var addBinary = function(a, b) {
    let count = 0;
    let str = '';
    let len = Math.max(a.length,b.length);
    a = a.padStart(len,'0');
    b = b.padStart(len,'0');
    for(let i=len-1;i>=0;i--){
        let sum = count;
        sum += parseInt(a[i])+parseInt(b[i]);
        str += sum%2;
        count = Math.floor(sum/2)
    }
    str += count ==1 ? 1 : '';
    return str.split('').reverse().join('');
};
```
```
class Solution(object):
    def addBinary(self, a, b):
        """
        :type a: str
        :type b: str
        :rtype: str
        """
        maxLen = max(len(a),len(b))
        a = '0'*(maxLen-len(a)) + a
        b = '0'*(maxLen-len(b)) + b
        arr = ''
        count = 0
        for i,j in zip(a[::-1],b[::-1]): # python 中从后向前取 [::-1]
            sums = count
            sums += int(i)+int(j)
            arr += str(sums%2)
            count = sums//2
            
        return '1'+arr[::-1] if count == 1 else arr[::-1]
```

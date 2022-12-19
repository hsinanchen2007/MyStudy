无需新数组，直接循环，如果遇到奇数则扔到数组后方；
只需要一个变量记录第一个奇数位置即可。
```js
/**
 * @param {number[]} A
 * @return {number[]}
 */
var sortArrayByParity = function(A) {
    var sio = A.length; // start index of odd
    var swap = function(arr, a, b){
        let t = arr[a];
        arr[a] = arr[b];
        arr[b] = t;
    }
    for(let i = 0; i < sio-1;){
        if(A[i] & 1){ // 奇数
            swap(A, i, sio-1);
            sio--;
        } else {
            i++;
        }
    }
    return A;
};
```

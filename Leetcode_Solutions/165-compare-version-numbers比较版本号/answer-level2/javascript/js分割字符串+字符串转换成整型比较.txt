```
/**
 * @param {string} version1
 * @param {string} version2
 * @return {number}
 */
var compareVersion = function(version1, version2) {
    let arr1 = version1.split(".");//分割字符串
    let arr2 = version2.split(".");

    let temp = 0;
    let len = Math.max(arr1.length,arr2.length);
    for(let i=0;i<len;i++){

        let data1 = 0,data2 = 0;
        if(i<arr1.length){
            data1 = parseInt(arr1[i]);
        }
        if(i<arr2.length){
            data2 = parseInt(arr2[i]);
        }
        
        if(data1<data2){
            return -1;
        }else if(data1 > data2){
            return 1;
        }
    }
    return 0;
};
```

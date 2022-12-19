var getLeastNumbers = function(arr, k) {
    arr.sort(function(a,b){return a - b;});
    return arr.slice(0,k);
};

数组排序，然后裁剪数组即可
比较简单，不赘述，看代码即可
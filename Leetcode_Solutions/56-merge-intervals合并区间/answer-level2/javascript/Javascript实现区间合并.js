```
/**
 * @param {number[][]} intervals
 * @return {number[][]}
 */
//将重复区间进行合并
function mergeRepeat(left,right){
    let left_max = left[1];
    let left_min = left[0];

    let right_max = right[1];
    let right_min = right[0];

    let min = left_min<right_min?left_min:right_min;
    let max = left_max>right_max?left_max:right_max;
    return [min,max];
}

//检查是否有重复区间
function IsRepeat(left,right){
    let left_max = left[1];
    let left_min = left[0];

    let right_max = right[1];
    let right_min = right[0];

    if(left_min>right_max|| left_max<right_min){
        return 0;//没有重复区间
    }
    return 1;//有重复区间
}
function sortByindexZero(num){
    return function(a,b){
        var value1 = a[num];
        var value2 = b[num];
        return value1-value2;
    }
}
var merge = function(intervals) {
    let i =0;
    //排序 按照数组内数组的第一个元素从小到大排序
    intervals.sort(sortByindexZero(0));
    while(i<intervals.length-1){
        if(IsRepeat(intervals[i],intervals[i+1])==1){//如果重复
            intervals[i+1] = mergeRepeat(intervals[i],intervals[i+1]);
            intervals[i] = "";
        }
        i++;
    }
    return intervals.filter(item=>item!="");
};
```

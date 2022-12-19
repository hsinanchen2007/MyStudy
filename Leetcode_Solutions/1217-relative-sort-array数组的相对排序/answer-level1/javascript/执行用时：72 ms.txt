

```
/**
 * @param {number[]} arr1
 * @param {number[]} arr2
 * @return {number[]}
 */
var relativeSortArray = function(arr1, arr2) {
    var ans=[];
    for(let i=0;i<arr2.length;i++){
        check(arr2[i]);    
    }
    function check(obj){
        if(arr1.indexOf(obj)>-1){
            arr1.splice(arr1.indexOf(obj),1);
            ans.push(obj);
            check(obj);
        }
    }
    function sb(a,b){
        return a-b;
    }
    arr1.sort(sb);
    for(let i=0;i<arr1.length;i++){
        ans.push(arr1[i]);
    }
    return ans;
    
};

```

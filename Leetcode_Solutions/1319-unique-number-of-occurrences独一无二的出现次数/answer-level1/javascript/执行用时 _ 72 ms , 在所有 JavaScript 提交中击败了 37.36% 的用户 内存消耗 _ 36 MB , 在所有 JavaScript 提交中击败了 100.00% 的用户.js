```
function groupBy( array , f ) {
    let groups = {};
    array.forEach( function( o ) {
        let group = JSON.stringify( f(o) );
        groups[group] = groups[group] || [];
        groups[group].push( o );
    });
    return Object.keys(groups).map( function( group ) {
        return groups[group];
    });
}
var uniqueOccurrences = function(arr) {
    let arrNew =  groupBy(arr,item=>[item]).map(item=>item.length);
    return arrNew.length===[...new Set(arrNew)].length
};
```

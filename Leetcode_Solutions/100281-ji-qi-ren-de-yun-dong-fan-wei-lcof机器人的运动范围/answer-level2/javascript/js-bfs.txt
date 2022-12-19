
每次向右、向下走，走过的加入已访问记录。
```
/**
 * @param {number} m
 * @param {number} n
 * @param {number} k
 * @return {number}
 */
var movingCount = function(m, n, k) {
    var arr = [[0,0]];
    var res = 0;
    var isVisited = {};
    var helper = (m,n,k,arr) => {
        if(arr.length === 0) return;
        let next = [];
        for(var i = 0 ; i < arr.length; i++){
            let [x,y] = arr[i];
            let key = x + '-' + y;
            if(x >= m || y >= n || isVisited[key] || (''+x+y).split('').reduce( (a,b) => ~~a + ~~b ) > k ){
                continue;
            }
            res++;
            isVisited[key] = true;
            next.push([x+1,y],[x,y+1]);
            helper(m,n,k,next);
        }
    }
    helper(m,n,k,arr);
    return res;
};
```

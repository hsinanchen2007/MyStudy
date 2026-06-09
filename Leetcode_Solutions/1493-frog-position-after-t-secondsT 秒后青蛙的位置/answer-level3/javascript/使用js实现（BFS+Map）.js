### 解题思路
1、注意是在定的时间内能够在目标点上
2、如果青蛙不能跳到任何未访问过的顶点上，那么它每次跳跃都会停留在原地。
### 代码

```javascript
 var frogPosition = function(n, edges, t, target) {
        if (n == 1) {
        return 1;
      }
      var t0 = 1;
      // 待遍历数组
      var arr = [1];
      //  使用map找出每个顶点的连线
      edges = edges.map(ele => {
      
        if (ele[0] > ele[1]) {
          return ele.reverse();
        } else {
          return ele;
        }
      });
      var map = new Map();
      for (var i = 0; i <= edges.length - 1; i++) {
        if (map.get(edges[i][0])) {
          map.get(edges[i][0]).push(edges[i][1]);
        } else {
          map.set(edges[i][0], [edges[i][1]]);
        }
      }
      var res = [1];
      while (t0 <= t && arr.length != 0) {
        var temp = [];
        var restemp = [];
        for (i = 0; i < arr.length; i++) {
          var temp2 = map.get(arr[i]);
          if (!temp2) {
            temp2 = [];
          }
          var changes = res[i] * temp2.length;
          for (var j = 0; j < temp2.length; j++) {
            temp.push(temp2[j]);
            restemp.push(changes);
            if (
              (t == t0 && temp2[j] == target) ||
              (t != t0 && temp2[j] == target && !map.get(temp2[j]))
            ) {
              return 1 / restemp[restemp.length - 1];
            }
          }
        }
        arr = temp;
        res = restemp;
        t0++;
      }

      return 0;
    };
    
```
![image.png](https://pic.leetcode-cn.com/a26d45fdeff3db3c5b348c83764e00595a55d7dce2d9686e4b2c911ed5468fdb-image.png)

这道题目和54题有些类似，我们可以用模拟一个人，转圈走路填数的方法
![image.png](https://pic.leetcode-cn.com/5f3e9d088d49ec603fddbabf3f39de35f476c8934bf0b92977caaeca63973cfc-image.png)
就是按照图片上的这个方法，顺序是：上 右 下 左 的顺序
具体的实现思路：
  1.初始化一个n长度的数组，然后开始填数
  2.上 右 下 左 四个方向，从外到内循环每一条边，每个方向循环填数的逻辑封装在changeDirection的四个方法中
  3.递归的终止条件是：填完(n*n)个数，
```
var generateMatrix = function(n) {
  let end = n * n,
      start = 1, // 初始化，从1开始填
      start_x = 0,
      start_y = 0,
      limit_x = n,
      limit_y = n,
      result = [],
      direction = 'top'; // 从顶边开始
  for ( let k = 0; k < n; k++ ) {
    result.push( [] );
  }
  var changeDirection = {
    top: function() {
      direction = 'right';
      for ( let i = start_x; i < limit_x; i++ ) {
        result[start_y][i] = start;
        start = start + 1;
      }
      start_y++;
    },
    right: function() {
      direction = 'bottom';
      for ( let i = start_y; i < limit_y; i++ ) {
        result[i][limit_x - 1] = start;
        start = start + 1;
      }
      limit_x--;
    },
    bottom: function() {
      direction = 'left';
      for ( let i = limit_x - 1; i >= start_x; i-- ) {
        result[limit_y - 1][i] = start;
        start = start + 1;
      }
      limit_y--;
    },
    left: function() {
      direction = 'top';
      for ( let i = limit_y - 1; i >= start_y; i-- ) {
        result[i][start_x]  = start;
        start = start + 1;
      }
      start_x++;
    }
  };
  var backtrack = function() {
    if ( start === end + 1 ) {
      return ;
    }
    else {
      changeDirection[ direction ]();
      backtrack();
    }
  }
  backtrack();
  return result;
};

```

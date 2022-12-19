利用递归求出两个水壶能装的最小升数，想满足条件Z有两种情况
1.Z=0; 这是不管两个水壶什么状态都能满足条件
2.Z<=x+y,并且Z是两个水壶容量的最大公约数的倍数

var canMeasureWater = function(x, y, z) {
     let flag = false;
     //递归求x,y的最大公约数
     var gcd = function(x, y) {
          if ( ! y) {
              return x;
          }
          return gcd(y, x % y);
      };

     let m = gcd(x,y);
     //判断z是否能整除最大公约数（注意z的值）
     if(z<=(x+y)&&z%m==0||z==0){
         flag = true;
     }
     return flag;
};


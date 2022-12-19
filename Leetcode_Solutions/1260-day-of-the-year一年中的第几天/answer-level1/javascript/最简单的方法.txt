![image.png](https://pic.leetcode-cn.com/a910a61a62b5408f4825248b79477edb3b06fc162680ca89ae716127399b375a-image.png)


var dayOfYear = function(date) {
            var year = date.substr(0,4);
            var mouth = date.substr(5,2);
            var day = date.substr(8,2);
            var sum = 0;
            var days = new Array(31,28,31,30,31,30,31,31,30,31,30,31);
            if(year%400==0||(year%4==0&&year%100!=0)){
                days[1]=29;
            }
            for(var i=0;i<mouth-1;i++){
                sum = sum+days[i];
            }
            sum = sum+day*1;
            return sum;
};
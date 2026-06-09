直线方程斜截式写法 y= kx + C
k = (y2-y1)/(x2-x1)
c = y1-kx1
上面的 带数字编号的字母都是已知的数字
利用两点求出只想方程的K和c
然后验证就可以了

var checkStraightLine = function(coordinates) {
    let mid = coordinates;
    let length = mid.length;
    if(mid[0][0] != mid[1][0]){
        if(mid[1][0] != mid[1][1]){
            let k = (mid[1][1]-mid[0][1])/(mid[1][0]-mid[0][0]);
            let c = mid[0][1]-k*mid[0][0];
            for(let i = 2; i < length-1;i++){
                if(mid[i][1] != mid[i][0]*k+c){
                    return false;
                } 
            }
            return true;
        }else{
            for(let i =1;i < length-2;i++){
                if(mid[i][1] != mid[i+1][1]){
                    return false;
                }
            return true;
        }
        }
    }else{
        for(let i =1;i < length-2;i++){
            if(mid[i][0] != mid[i+1][0]){
                return false;
            }
            return true;
        }
    }
};
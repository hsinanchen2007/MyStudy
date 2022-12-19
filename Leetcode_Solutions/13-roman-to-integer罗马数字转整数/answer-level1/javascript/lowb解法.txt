var romanToInt = function(s) {
    var num = 0;
    var arr = s.split('');
    for(var i=0;i<arr.length;i++){
        switch(arr[i]){
            case 'I' : num+=1;
            break;
            case 'V' : num+=5;
                break;
            case 'X' : num+=10;
                break;
            case 'L' : num+=50;
                break;
            case 'C' : num+=100;
                break;
            case 'D' : num+=500;
                break;
            case 'M' : num+=1000;
        }
    }
    if (s.indexOf('IV') != -1 || s.indexOf('IX') != -1 ){
        num-=2;
    }
    if(s.indexOf('XL') != -1 || s.indexOf('XC') != -1 ){
        num-=20;
    }
    if(s.indexOf('CD') != -1 || s.indexOf('CM') != -1 ){
        num-=200;
    }
    return num;
};
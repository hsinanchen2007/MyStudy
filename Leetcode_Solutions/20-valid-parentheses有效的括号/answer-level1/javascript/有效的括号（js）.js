括号有效的判断：
1.右括号必须对应上一个左括号（右括号前已经对应的括号无视）。
2.无多余的左括号。

~~~


const fl={ 
    '(':')',
    '{':'}',
    '[':']',
};  //编辑器里写符号太烦了

const fr={
    ')':'(',
    '}':'{',
    ']':'[',
};

/**
 * @param {string} s   
 * @return {boolean}   
 */   
var isValid = function(s) {   
    let arr=s.split('');   
    const cache=[];  
    for(let v of arr){  
        if(fl[v]){   
            cache.splice(0,0,v);
        }else if(fr[v]){
            if(cache && cache[0]===fr[v]){
                cache.splice(0,1);
            }else{
                return false;
            }
        }
    }
    return cache.length===0;
};

~~~
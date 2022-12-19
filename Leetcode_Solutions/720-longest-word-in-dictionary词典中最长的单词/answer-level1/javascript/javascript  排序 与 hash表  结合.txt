```
var longestWord = function(words) {
    //按长度排序，如果长度相同，按字典序降序排列,
    let map = new Map();
    words.sort(function(a,b){
        if(!map.has(a)) map.set(a,1);
        if(!map.has(b)) map.set(b,1);
        if(a.length==b.length){
            for(let i=0;i<a.length;++i){
                if(a[i]!=b[i])  return b[i].charCodeAt()-a[i].charCodeAt();
            }
        } else return a.length-b.length;
    });
        //字典序的降序排列保证同长度下满足条件的第一个一定是字典序最小的
    for(let i=words.length-1;i>=0;--i){   
        let flag = true;
            //如果到了一个长度的字符必然是true
        for(let j=0;j<words[i].length-1;++j){
            let temp = words[i].substr(0,j+1);
            if(!map.has(temp)) flag = false;
        }
        if(flag) return words[i];
    }
    return "";
};
```

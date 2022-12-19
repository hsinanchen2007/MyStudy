```
var groupAnagrams = function(strs) {
    var res=[];
    var map={};//new Map();
    for(let i=0;i<strs.length; i++){
        let tmp=strs[i].split('').sort();
        if(map[tmp]==undefined){
            map[tmp]=[strs[i]];
        }
        else{
            map[tmp].push(strs[i])
        }
    }
    for(let el in map){
        res.push(map[el])
    }
    return res;
};

```

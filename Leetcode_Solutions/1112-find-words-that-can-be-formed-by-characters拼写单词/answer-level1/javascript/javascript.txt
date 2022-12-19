```javascript []
/**
 * @param {string[]} words
 * @param {string} chars
 * @return {number}
 */
var countCharacters = function(words, chars) {
    let map=new Map();
    //每个字母出现几次记录在map里
    for(c of chars){
        if(map.has(c))
         map.set(c,map.get(c)+1);
        else
         map.set(c,1); 
    }
    
    //遍历words 来检查每个单词
    let res=0;
    for(w of words)
    {
      let temp=w.split('');
      if(check(temp,map))
          res+=temp.length;
    }
    return res;
    
    //检查是否满足条件
    function check(word,map){
        var newMap = new Map(map);//复制一个map
        let back=true;
         for(w of word){
              if(newMap.has(w)&&newMap.get(w)>0)
                  newMap.set(w,newMap.get(w)-1);
             else
                 back=false;
         }
        return back;
    }
};
```


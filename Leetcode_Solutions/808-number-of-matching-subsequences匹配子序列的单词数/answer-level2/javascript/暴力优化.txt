![捕获.PNG](https://pic.leetcode-cn.com/18499e0813fb9a28925f2dbc963fc6a87e55e584269321288a875cd746e7602d-%E6%8D%95%E8%8E%B7.PNG)
```
var numMatchingSubseq = function(S, words) {
        let count = 0,
			startIndex = -1;
        for(const j of words){
              let flag = false;
				for(let m = 0; m < j.length; m++){
                    let tempIndex = S.indexOf(j[m], startIndex + 1);
                    if(tempIndex != -1){
                        startIndex  = tempIndex;
                        flag = true;
					}else{
                        flag = false;
                        break;
					}
				}
            startIndex = -1;
            flag === true?++count:null
        }
        return count;
    };
```




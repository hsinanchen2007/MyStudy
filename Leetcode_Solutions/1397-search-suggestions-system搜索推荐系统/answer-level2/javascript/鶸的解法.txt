```
var suggestedProducts = function(products, searchWord) {
  let result = []
  for(let i = 0; i < searchWord.length; i++){
    let res = []
    let str = searchWord.slice(0,i+1)
    let len = str.length
    for(let j = 0; j < products.length; j++){
        if(products[j].indexOf(str)==0&&str!=''){
        res.push(products[j])
        }
    }
    res.sort()
    result.push(res.slice(0,3))
  }
  return result
};
```
根本没想那么多....啊啊啊，也没想到前缀树....

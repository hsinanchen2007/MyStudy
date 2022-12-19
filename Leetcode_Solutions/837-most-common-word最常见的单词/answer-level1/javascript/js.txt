js
```
var mostCommonWord = function(paragraph, banned) {
    const Objbanned = {}
    for(let i = 0;i<banned.length;i++){
        Objbanned[banned[i]]=0
    }
    const arr = paragraph.toLowerCase().replace(/\W/g,' ').split(' ').filter(x=> !Objbanned.hasOwnProperty(x) && x !=='')
    const obj = {}
    let max = 0
    let revl = ''
    for(let i=0;i<arr.length;i++){
        if(!obj.hasOwnProperty(arr[i])) {
            obj[arr[i]] = 1
        } else {
            obj[arr[i]]++
        }
        if(max<obj[arr[i]]){
           max = obj[arr[i]]
           revl = arr[i]
        }
        
    }
    return revl
};
```

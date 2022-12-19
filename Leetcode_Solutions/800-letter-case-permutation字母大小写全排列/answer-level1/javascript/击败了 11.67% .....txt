```javascript
var letterCasePermutation = function(S) {
    let result = ['']
    for(const char of S){
        if(!isNaN(char)){
            result = result.map(str => `${str}${char}`);
        } else{
            result = [
                ...result.map(str =>
                    `${str}${char.toLowerCase()}` 
                    ),
                ...result.map(str =>
                    `${str}${char.toUpperCase()}`
                    ),
                ];
        }
    }

    return result;
};
```
```

/**
 * @param {string} s
 * @param {string} t
 * @return {character}
 */
var findTheDifference = function(s, t) {
    let newS = s;
    for (var i = 0; i < t.length; i++) {
        
        if (newS.indexOf(t[i]) === -1) {
            return t[i];
        }
        newS = newS.replace(t[i], '')
    }
    
};


```
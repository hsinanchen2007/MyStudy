```
var flipAndInvertImage = function(A) {
    A.forEach(item => {
        item.reverse();
        for (let i = 0; i < item.length; i++) {
            if (item[i] === 0) {
                item[i] = 1;
            } else {
                item[i] = 0;
            }
        }
    });
    
    return A
};
```

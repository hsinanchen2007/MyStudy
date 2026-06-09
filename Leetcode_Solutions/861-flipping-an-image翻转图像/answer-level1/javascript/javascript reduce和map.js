```
var flipAndInvertImage = function (A) {
    let a1 = A.reduce((prev, curr) => {
        prev.push(curr.reverse().map(a => a ^ 1));
        return prev;
    }, []);
    return a1;
};
```

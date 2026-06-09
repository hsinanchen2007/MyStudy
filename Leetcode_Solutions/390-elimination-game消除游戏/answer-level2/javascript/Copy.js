```

var lastRemaining = function (n) {

    let currentGap = 1;
    let currentHead = 1;
    let turn = 1;
    while (n !== 1) {
        const prevN = n;
        n = Math.floor(prevN / 2);
        if (turn % 2 === 1 || prevN % 2 === 1) {
            currentHead += currentGap;
        }
        currentGap *= 2;
        turn++;
    }
    return currentHead;


};



```
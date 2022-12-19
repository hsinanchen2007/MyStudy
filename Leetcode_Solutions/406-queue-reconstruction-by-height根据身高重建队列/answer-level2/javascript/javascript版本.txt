```
var reconstructQueue = function(people) {
    people.sort((a, b) => a[0] === b[0] ? a[1] - b[1] : b[0] - a[0]);
    const res = [];

    for (let i of people)
        res.splice(i[1], 0, i);

    return res;
};
```

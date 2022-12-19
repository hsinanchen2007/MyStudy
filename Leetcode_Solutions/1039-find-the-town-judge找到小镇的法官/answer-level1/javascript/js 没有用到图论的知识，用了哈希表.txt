```
var findJudge = function(N, trust) {
    const record = trust.reduce((t, i) => {
        t[i[1]] = 1;
        return t;
    }, {});
    let i = trust.length;
    if(!i) return 1;
    while(i--) if(record[trust[i][0]]) delete record[trust[i][0]];
    const res = Object.keys(record);
    if(res.length !== 1) return -1;
    const people = {};
    i = trust.length;
    while(i--) if(trust[i][1] === +res[0]) people[trust[i][0]] = 1;
    return Object.keys(people).length === N - 1 ? res[0] : -1;
};
```

```
var findJudge = function(N, trust) {
	if (N == 1 && trust.length == 0) {
        return 1
    }
    // 相信法官的人
    let peoples = new Set();
    // 可能为法官的人
    let judges = new Set();
    trust.forEach((item) => {
    	judges.add(item[1])
    })
    trust.forEach((item) => {
    	if (judges.has(item[0])) {
    		judges.delete(item[0])
    	}
    })
    let judge = [...judges][0]
    if (judges.size == 1) {
        trust.forEach((item) => {
            if (item[1] === judge) {
                peoples.add(item[0])
            }
        })
    }
    if (peoples.size == N - 1 && !peoples.has(judge)) {
    	return judge
    }
    return -1
};
```

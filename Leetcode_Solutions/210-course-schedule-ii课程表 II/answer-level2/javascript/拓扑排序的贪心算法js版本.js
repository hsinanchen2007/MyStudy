
```
//  Greedy
var findOrder = function(numCourses, prerequisites) {
    const inDegrees = Array(numCourses).fill(0);
    const res = [];
    const G = Array(numCourses).fill(0).map(_ => []);

    for (let e of prerequisites) {
        G[e[1]].push(e[0]);
        inDegrees[e[0]]++;
    }

    while (res.length < numCourses) {
        let hasCycle = true;

        for (let i = 0; i < numCourses; i++) {
            if (inDegrees[i] === 0) {
                hasCycle = false;
                inDegrees[i] = -1;
                res.push(i);

                for (let w of G[i]) {
                    inDegrees[w]--;
                }
            }
        }

        if (hasCycle) return [];
    }

    return res;
}
```
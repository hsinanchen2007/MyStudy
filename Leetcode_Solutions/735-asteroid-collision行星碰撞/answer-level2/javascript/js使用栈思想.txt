```
/**
 * @param {number[]} asteroids
 * @return {number[]}
 */
 var asteroidCollision = function(asteroids) {
    const len = asteroids.length
    const res = []
    for (let i = 0; i < len; i++) {
        const aster = asteroids[i]
        if (!res.length) {
           res.push(aster)
        } else {
            const pop = res[res.length - 1]
            if (pop < 0 || aster > 0) {
                res.push(aster)
            } else {
                if (pop + aster > 0) {
                    continue
                } else if (pop + aster < 0) {
                    res.pop()
                    i--
                } else if (pop + aster === 0) {
                    res.pop()
                }
            }
        }
    }
    return res
};
```

```
/**
 * @param {number[]} asteroids
 * @return {number[]}
 */
var asteroidCollision = function(asteroids) {
    // Guards
    if (asteroids.lenght <= 1) return asteroids
    // Processing
    return boom(asteroids, 0)
};


function boom(asteroids) {
    asteroids.forEach((left, index) => {
        const rightIndex = index+1
        if (rightIndex <= asteroids.length-1) {
            const right = asteroids[index+1]
            // console.log(asteroids, left, right)
            const willBoom = left>0 && right<0
            if (willBoom) {
                if (Math.abs(left)>Math.abs(right)) {
                    // console.log("a")
                    asteroids[index+1] = "_"
                } else if (Math.abs(left)<Math.abs(right)) {
                    // console.log("b")
                    asteroids[index] = "_"
                } else {
                    // console.log("c")
                    asteroids[index]!==0 && (asteroids[index] = "_")
                    asteroids[index+1]!==0 && (asteroids[index+1] = "_")
                }
            }
        }
    })
    const res = asteroids.filter(i => i!=="_")
    if (res.length != asteroids.length) {
        return boom(res)
    } else {
        return res
    }
}
```

把头和尾巴拿出来，中间的逐次比较。
```
const maxDistToClosest = (seats) => {
    let max = 0, target = 0, left = 0, right = 0;
    for (let index = 0; index < seats.length; index++) {
        const cur = seats[index];
        if (!cur) {
            target++;
            if (target < max) continue;
            if (index + 1 === target) {
                left++;
            } else if (index + 1 === seats.length) {
                right = target;
            } else if (seats[index + 1] === 1 && index + 1 !== target && index !== seats.length - 1) {
                const temp = target / 2;
                if (temp > max)
                    max = temp;
            }
        } else {
            target = 0;
        }
    }
    return Math.max(left, right, max);
};
```

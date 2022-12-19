# 使用一个map的做法，用正值和负值分别去存储secret和guess中的可能存在的cow。
```
/**
 * @param {string} secret
 * @param {string} guess
 * @return {string}
 */
var getHint = function(secret, guess) {
    let map = new Map();
    let bull = 0;
    let cow = 0;

    for (let i = 0; i < secret.length; i++) {
        if (secret[i] === guess[i]) {
            bull++;
        } else {
            let count = ~~map.get(secret[i]);

            if (count < 0) {
                cow++;
            }

            map.set(secret[i], ++count);

            count = ~~map.get(guess[i]);

            if (count > 0) {
                cow++;
            }

            map.set(guess[i], --count);
        }
    }

    return `${bull}A${cow}B`;
};
```

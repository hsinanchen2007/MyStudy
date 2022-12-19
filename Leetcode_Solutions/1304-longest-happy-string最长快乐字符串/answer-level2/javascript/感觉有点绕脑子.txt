### 解题思路
![image.png](https://pic.leetcode-cn.com/ed5d5a35690bc0d6fd84f150d6762694b9d4cb52de652f657b6110ba7f5d7285-image.png)

字符也是abc，数量也是abc，脑子有点转不过来，参考了首赞的几个题解，先排序，这个降序排序让我想了半天，最后搞了三个obj怼进arr排序。不管效率高不高，的确方便理解了。

数量最多的拿出2个或1个，若和输出字符末尾撞车了，就从数量次多的里面选取。每次选取插入后要重新排序三个obj。。
这样应该最后只剩下一种字符了，遍历一下输出字符串，往里面插2个或1个。

说实话，这题AC是靠运气，感觉现在还没完全理解。。。。。

### 代码

```javascript
/**
 * @param {number} a
 * @param {number} b
 * @param {number} c
 * @return {string}
 */
var longestDiverseString = function (a, b, c) {
    let arr = [{
        char: "a",
        qty: a
    }, {
        char: "b",
        qty: b
    }, {
        char: "c",
        qty: c
    }];
    let str = "";
    while (true) {
        arr.sort((objA, objB) => objB.qty - objA.qty);
        if (arr[0].char != str[str.length - 1]) {
            if (arr[0].qty >= 2) {
                str += arr[0].char.repeat(2);
                arr[0].qty -= 2;
            } else if (arr[0].qty === 1) {
                str += arr[0].char;
                arr[0].qty -= 1;
            } else {
                return str;
            }
        } else if (arr[1].char != str[str.length - 1]) {
            if (arr[1].qty >= 2) {
                str += arr[1].char.repeat(2);
                arr[1].qty -= 2;
            } else if (arr[1].qty === 1) {
                str += arr[1].char;
                arr[1].qty -= 1;
            } else {
                break;
            }
        } else {
            break;
        }
    }
    arr.sort((objA, objB) => objB.qty - objA.qty);
    for (let i = 0; i < str.length - 1; i++) {
        if (arr[0].qty) {
            if (arr[0].char != str[i] && arr[0].char != str[i + 1]) {
                if (arr[0].qty >= 2) {
                    str = str.substr(0, i + 1) + arr[0].char.repeat(2) + str.substr(i + 1, str.length);
                    arr[0].qty -= 2;
                } else {
                    str = str.substr(0, i + 1) + arr[0].char + str.substr(i + 1, str.length);
                    arr[0].qty--;
                }
            }
        }
    }
    return str;
};
```
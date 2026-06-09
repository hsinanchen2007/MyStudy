```js
var largestNumber = nums =>
    nums
        .map(String)
        .sort((a, b) => b.concat(a) - a.concat(b))
        .join("")
        .replace(/^0+/, "") || "0";

```
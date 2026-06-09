*法一*

```js
var nextGreatestLetter = function(letters, target) {
    for(let i = 0; i < letters.length; i++){
        if(letters[i] > target){
            return letters[i]
        }
    }
    return letters[0]
};
```

*法二：二分法*

```js
var nextGreatestLetter2 = function(letters, target) {
    let left = 0;
    let right = letters.length - 1;
    while(left <= right) {
        let middle = parseInt((left + right) / 2);
        if (target < letters[middle]) {
            right = middle - 1;
        } else {
            left = middle + 1;
        }
    }
    return letters[left % letters.length];
};
```
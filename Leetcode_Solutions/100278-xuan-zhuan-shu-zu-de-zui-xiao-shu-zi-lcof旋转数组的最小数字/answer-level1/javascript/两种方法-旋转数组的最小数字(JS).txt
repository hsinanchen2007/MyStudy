## 1
```js
var minArray = function(numbers) {
    return Math.min(...numbers);
};
```
## 2
```js
var minArray = function(numbers) {
    let left = 0,
        right = numbers.length - 1;
    while (left < right) {
        let mid = Math.floor((right + left) / 2);
        if (numbers[mid] > numbers[right]) 
            left = mid + 1;
        else if(numbers[mid] < numbers[right])
            right = mid;
        else right -= 1;
    }
    return numbers[left];
};
```
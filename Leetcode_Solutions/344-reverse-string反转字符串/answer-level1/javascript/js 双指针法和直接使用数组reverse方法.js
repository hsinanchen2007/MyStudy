```
//法一、双指针法
var reverseString = function(s) {
    let start = 0;
    let end = s.length - 1;
    while(start < end) {
        [s[start], s[end]] = [s[end], s[start]]
        // let temp = s[start];
        // s[start] = s[end];
        // s[end] = temp;
        start++;
        end--
    }
};
//法二、
var reverseString = function(s) {
    s.reverse()
};

```

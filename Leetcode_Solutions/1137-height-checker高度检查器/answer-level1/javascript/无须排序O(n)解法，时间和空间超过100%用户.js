初学js，特地重刷一遍

```js
/**
 * @param {number[]} heights
 * @return {number}
 */
var heightChecker = function(heights) {
    var num = 0;
    var map = new Array();
    
    for(var i = 0; i < heights.length; i++) {
        if(map[heights[i]] >= 0) {
            map[heights[i]]++;
        } else {
            map[heights[i]] = 1;
        }
    }
    
    var flag = 0;
    for(var j = 0; j < 101; j++) {
        var c = map[j];
        if(!c) continue;
        for(var k = flag; k < flag + c; k++) {
            if(heights[k] != j) {
                num++;
            }
        }
        flag += c;
    }
    
    return num;
};
```

![TIM截图20191105183401.png](https://pic.leetcode-cn.com/56419adc6c9aa8c79996219a87104db4d36ffec1a36f613fd29d07bd8a7babce-TIM%E6%88%AA%E5%9B%BE20191105183401.png)

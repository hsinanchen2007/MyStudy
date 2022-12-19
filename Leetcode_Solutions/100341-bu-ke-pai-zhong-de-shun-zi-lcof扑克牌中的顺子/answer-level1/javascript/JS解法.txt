### 解题思路
思路：
1. 数组长度为5
2. max - min < 5
3. 除0以外无重复的扑克牌

### 代码

```javascript

var isStraight = function(numbers) {
    let max=-1;
    let min=14;
    if(numbers.length!==5){
        return false
    }
    numbers.sort((a,b) => a-b)
    for(let i=0;i<numbers.length;i++){
        if(numbers[i]<0 || numbers[i]>13 || numbers[i]===max || numbers[i]===min){
            return false
        }
        if(numbers[i]===0){
            continue    
        }
        if(numbers[i]>max){
            max=numbers[i]
        }
        if(numbers[i]<min){
            min=numbers[i]
        }
    }
    if(max-min<5){
        return true
    }
    return false
};

```
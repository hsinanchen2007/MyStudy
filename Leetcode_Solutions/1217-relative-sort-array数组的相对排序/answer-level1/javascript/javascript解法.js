代码是参考了其他人的+自己想了一点，觉得有一个挺有趣的点需要注意，就是那个continue。
```javascript
var relativeSortArray = function(arr1, arr2) {
    let result = [];
    
    while(arr2.length){
        let i = 0;
        let target = arr2.shift();//shift：移除数组的第一项。因此arr2长度会不断减小，至0时跳出外循环
        
        while(i <= arr1.length){
            if(arr1[i] === target){
                result.push(arr1[i]);
                arr1.splice(i,1);//删除位置i的一项。因此arr1长度也会减小
                continue;
            }
            i++;
        }
    }
    
    return result.concat(arr1.sort((a,b) => a - b));
};
```
**如果没有continue**，会出现：
输入
[2,3,1,3,2,4,6,7,9,2,19]
[2,1,4,3,9,6]
输出
 [2,2,2,1,4,**3,9,6,3**,7,19]
预期结果
[2,2,2,1,4,**3,3,9,6**,7,19]

我的输出里，另外一个3跑去其他地方了。为什么？
**假设没有continue**，当进行了splice之后，位置i的元素会删掉，i后面的元素会往前补，但变量i会照常加1，这就导致有可能出现直接错过的情况。
举个栗子，已知前提条件：i为2，arr1[2]和arr1[3]都跟target相匹配。开始解题：
因为arr1[2]==target，所以会将值push到result中，然后删掉i为2的值即arr1[2]。**此时，arr1[3]会挪到i为2的位置中，变成了arr1[2]**，arr1[4]会挪到i为3的位置中。这时候，执行完if语句，**开始执行i++**。i变成了3，**错过了**能跟target相匹配的arr1[2]。

所以在满足if条件的语句里加一个continue，这样可阻止上述的情况发生，即跳过i++，进行下一轮while循环，此时i还是之前的i，如果碰到上述的情况，依旧能匹配到往前挪了一个位置的值。

（PS：第一次发题解，不知道自己有没有讲清楚，觉得自己有点啰嗦。如果有错误请在评论区告诉我~
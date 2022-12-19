### 解题思路
第一种方法运用双循环，每次结果保留较大值；
第二种方法运用快慢指针，执行效果与第一种类似；
从提交结果来看，第一种方法略优。

### 代码

```javascript
/**
 * @param {number[]} height
 * @return {number}
 */
var maxArea = function(height) {
    // let num=0; //第一种方法
    // for(let i=0;i<height.length-1;i++){
    //     for(let j=i+1;j<height.length;j++){
    //         num=Math.max(num, (j-i)*Math.min(height[i],height[j]))
    //     }
    // }
    // return num
    
    let a=0,b=1,num=0; //第二种方法
    while(a<height.length-1){
        if(b<height.length){
            num=Math.max(num, (b-a)*Math.min(height[a],height[b]))
            b++
        }else if(b===height.length){
            a++
            b=a+1
        }
    }
    return num
};
```
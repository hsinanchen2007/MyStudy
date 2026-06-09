## 分析问题：  

1. 什么条件下`m!`末尾会有`0`？  
当`m!`中能因式分解出出来`5`时末尾会有`0`    

2. `m!`中的`0`的个数与何相关?    
	`i∊{a|0<a<=m}`的所有的正整数，所有的`i`中能因式分解出来`5`的个数即末尾的`0`的个数  
可以参考之前的题目：  [阶乘后的零](https://leetcode-c∊n.com/problems/factorial-trailing-zeroes/)

3. 结果的可能值为何？为什么   
	结果只可能是`0`或`5`，因为每隔`5`个数，	`i∊{a|0<a<=m}`中至少比之前的`m`多因式分解出来一个`5`，因此末尾的`0`会增多`k`个`k>=1`(注意`k`并非恒等于`1`，因为存在`25、50、75`等能分解出多个`5`的数，导致末尾`0`的数目会增加`1个或多个`)

3. 知道了`K`的值，能确定`m`的范围吗？  
能：`5*m<=K`，每`5`个数一组，每增加一组数`f(m)`会增加`1个或多个`，设`M=5*m`可以直接求`M!`的末尾的`0`的个数

4. 怎样快速找到结果值为`0` 或者 `5` ？  
当`f(M)<K`时可以将`M`增大、当`f(M)>K`时可以将`M`减小，知道找到`f(M)===K`或者找不到。当`f(M)===K`表示存在末尾`0`的个数为`k`个的，直接返回为`5`，否则直接返回为`0`  

## 对应代码：  

```js
//结果要么是0、要么是5
var preimageSizeFZF = function(K) {
    let min = 0,max = K+1;
    //2分查找
    while(min<max){
        let center = ~~((min+max)/2);
        let numZero = tools(center);
        if(numZero>K){
            max=center;
        }else if(numZero<K){
            min=center+1;
        }else{
            return 5;
        }
    }
    return 0;
    
    //5*m的阶乘的0的个数
    function tools(m){
        let result=m;
        while(m>0){
            m = Math.floor(m/5);
            result += m;
        }
        return result;
    }
};
```
1. 斐波那契数列的做法
2. 使用generator的函数 生成正确的外观数列执行到第n个为止
3. 个人认为这个和单链表的抽象数据类型很像
4. 时间复杂度O(n) 空间复杂度O(n)
5. 如果有错误 勿见笑
```
var countAndSay = function(n) {
    //斐波那契数列的做法
    //使用generator的函数 生成正确的外观数列执行到第n个为止
    //个人认为这是单链表的抽象数据类型之一  如果不对欢迎指正
    if(n === 1)return '1';
    const getcurr = function(prev){
        //根据上一个数生成下一个外观数列
        let value = '';
        for(let v of prev.match(/(\d)\1*/g)){
             value += `${v.length}${v[0]}`
        }
        return value;
    }
    const recursion = function* (){
        //无限循环获取外观数列集合
        let curr = '1';
        for(;;){
            yield curr;
            curr = getcurr(curr);
        }
    }
    let index = 1;
    for(let i of recursion()){
    //获取想要的外观数列
        if(index === n){
            return i;
        }else{
            index++;
        }
        
    }    
};
```


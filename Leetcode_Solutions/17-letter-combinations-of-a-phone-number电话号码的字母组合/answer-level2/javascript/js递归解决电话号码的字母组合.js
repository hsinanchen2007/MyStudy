### 解题思路
找规律，输入0个或者1个数字是特殊情况，其他都可以两个两个组合，两个组合之后合并成一个，再和下一个组合，直到所有映射的字母数组里面为1个为止，找到规律，递归解题。

### 代码

```javascript
/**
 * @param {string} digits
 * @return {string[]}
 */
var letterCombinations = function(digits) {

    //对电话号码做映射
    let map=[" ","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"];
    if(!digits){
        return [];
    }else if(digits.length===1){
        return map[digits].split('');
    }
    let num=digits.split('');
    let arr=[];//保存映射后的字母
    num.forEach(item=>{
        if(map[item]){
            //这里字符串会自动转数字
            arr.push(map[item]);
        }
    })
    //进行组合运算的函数
    let combine=(arr)=>{
        //声明临时变量保存每次两两结合的值
        //最外层的循环是遍历第一个元素 里层的循环是遍历第二个元素
        let temp=[];
        for(let i=0,ilength=arr[0].length;i<ilength;i++){
            for(let j=0,jlength=arr[1].length;j<jlength;j++){
                temp.push(`${arr[0][i]}${arr[1][j]}`);
            }
        }
        //splice方法，删除元素，插入元素，改变原数组
        arr.splice(0,2,temp);
        if(arr.length>1){
            combine(arr);
        }else{
            return temp;
        }
        //除了递归返回值，函数体最后还要有返回值 arr最后只剩一个元素
        return arr[0];
    }
    return combine(arr)
};
```
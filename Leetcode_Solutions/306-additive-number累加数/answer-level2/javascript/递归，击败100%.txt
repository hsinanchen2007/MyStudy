## 运行情况
![image.png](https://pic.leetcode-cn.com/60d0e64c9da92868f01c19557f19efb08f46908cf6a111559f3ed9f31efb6cca-image.png)

## 思路
- 找出第一组 first+second=sum  sum刚好在剩下的字符串首位
- 如果找不出一组，则false，找得到，递归判断

## 找出第一组
首先,前面的两个数的位数，肯定不能比第三位大，不然加起来肯定就会超过第三个了。
即 `first.length`只能取 `Math.floor(num.length/2)`
取出第一个数后，我们把第一个数从字符串中裁剪，然后选第二个数second
同理第二个数也是不能大于剩余字符串的一半长度。
取完第二个数以后，剔除，得到剩余字符串。

那么我们需要两层循环来遍历所有组合情况。
```
求: 112358
第一，第二个值的可能的情况如下（这里的情况是根据上面我们说的条件遍历的）
1+1 = 2
1+12 = 13
11+2 = 13
11+23 = 34
112+3 = 115

```
当我们取出，计算first+second的值sum，判断sum是否在剩余字符串的首位。
`rest.indexOf(sum)==0`
- 如果在，那么我们往右移动我们的first和second值,别忘了更新剩余字符串长度，即`first=second;second=sum;rest=rest.substring(sum.length)`
- 如果不在 return

递归以上过程即可。

## 题解
```
var isAdditiveNumber = function(num) {
    if(num.length<3){
        return false;
    }
    let ans = false;
    const backtrack = function(first,second,rest){
        if(first!=="" && second!==""){
            //不能为0的两位数，但是可以单个0
            if((first.length>1&&first[0]==="0")||(second.length>1&&second[0]==="0")){ return;}
            let sum = Number(first)+Number(second);
            if(rest.indexOf(sum)==0){
                //符合条件，往后推
                //注意类型转换，数字没有length属性
                rest = rest.substring(String(sum).length)
                if(!rest.length){
                    //当数组全部取完，那么即是累加数
                    ans = true;
                }
                backtrack(second,sum,rest);
            }
            return;
        }
        for(let i=1;i<Math.floor(rest.length/2)+1;i++){
            first = rest.substring(0,i);
            let temp = rest.substring(i);
            for(let j=1;j<Math.floor(temp.length/2)+1;j++){
                second = temp.substring(0,j);
                let temp2 = temp.substring(j);
                backtrack(first,second,temp2);
            }
        }
    }
    backtrack("","",num)
    return ans;
    
};
```
### 解题思路
遍历数组，通过判断前后项是否相同，相同则number+1，不相同则修改原数组并将统计出来的字符的个数（number）加在后面
![1580996634(1).jpg](https://pic.leetcode-cn.com/8d9952986462cb5b893d9d67da1d395d9b5e2cdf2c414569a3f8a16f4ba2db3f-1580996634\(1\).jpg)

### 代码

```javascript
/**
 * @param {character[]} chars
 * @return {number}
 */
var compress = function(chars) {
    // 遍历数组，通过判断前后项是否相同，相同则number+1，不相同则修改原数组并将统计出来的字符的个数（number）加在后面
    let number = 1;     //用来统计相同字符个数的变量
    for(let i = 0;i < chars.length;){   
        if(chars[i] === chars[i+1]){    //前后项相同则number++，同时继续向后遍历
            number++;
            i++;
        }else{          //如果前后项不相同，则通过判断number的大小来决定如何修改原数组
            if(number === 1){
                i++;     //统计的字符的个数为1，根据要求不用替代任何字符串，所以继续向后遍历
            }
            else{  //统计的字符的个数不为1，需要替代字符串（也就是需要修改原数组）       
                if(number > 1 && number < 10){      //统计的字符的个数为个位数
                    chars.splice(i-number+2,number-1,String(number));
                }
                else{          //统计的字符的个数为多位数（只考虑到两位数的情况）
                    let x = String(number)[0];
                    let y = String(number)[1];
                    chars.splice(i-number+2,number-1,x,y);
                }
                // 因为使用了splice()修改了原数组，所以需要设定确认索引i的位置
                i = i + 3 - number;
                number = 1;
            }
        }
    }
    return chars.length
};
```
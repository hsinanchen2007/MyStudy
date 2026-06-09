### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string} s
 * @param {number} numRows
 * @return {string}
 */
var convert = function(s, numRows) {
       let tmp = '';
    let stop = 0;
    let result = '';

    if(s.length == 1 || numRows === 1 || numRows >= s.length){
        return s;
    }

    while(stop < s.length){
        for(let i = numRows; i > 1; i--){
            let a = [];
            if(i === numRows){
                a = s.substr(stop,numRows);
                if(tmp){
                    //第二次整体循环再现有基础上拼接字符串
                    tmp.forEach(function(item,index){
                        if(a[index]){
                            tmp[index] = item + a[index];
                        }
                    })
                }else{
                    //第一次拆分成数组['a','b','c','d']
                    tmp = a.split('');
                }
                
                stop = stop + numRows;
            }else if(stop < s.length){
                //根据index找到对应行数进行拼接
                tmp[i-1] = tmp[i-1] + s.substr(stop,1);
                stop++;
            }
        }
    }

    return tmp.join('')
};
```

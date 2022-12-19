**跟大佬是比不了了**

只能从实际出发

**用户是傻子，不会老实输入正确格式**

所以在判断输入字符是否合法上消耗了很多

**（性能垃圾，内存消耗垃圾）**
*执行用时 :164 ms, 在所有 javascript 提交中击败了78.28%的用户*
*内存消耗 :43.4 MB, 在所有 javascript 提交中击败了7.09%的用户*

**刚入门，先刷题，以后再优化吧。**

``` javascript
 let regx ='[^IVXLCDM]';
      let res = [];
      let result = 0;
      let arr =new Map([ //所有可能组合
          ['I',1],
          ['IV',4],
          ['V',5],
          ['IX',9],
          ['X',10],
          ['XL',40],
          ['L',50],
          ['XC',90],
          ['C',100],
          ['CD',400],
          ['D',500],
          ['CM',900],
          ['M',1000]
      ])
     if(!s.match(regx)){   //判断是否为基本罗马数字   
        for(let i =0;i<s.length;i++){   //分割字符为数组
            let temp = arr.get(s[i]);
            res.push(temp); //转化为数字
        }           
        for(let j=0;j<res.length;j++){  //每次比较两个字符
            if(res[j]>res[j+1]){    //左大于右时
                result+=res[j];        //正常加
                continue;
            }
            //右大于左，且确认为符合特殊规则
            else if(res[j]<res[j+1]&&(res[j+1]-res[j])/res[j]==4||(res[j+1]-res[j])/res[j]==9){ 
                result=result+res[j+1]-res[j]; //先减后加
                j=j+1;//跳过特殊规则位置
                continue;
            }
            //出现2个连续合法格式(I,X,C,M)字符
            else if(res[j+1]&&res[j]==res[j+1]&&(res[j]==1||res[j]==10||res[j]==100||res[j]==1000)){
                //判断连续合法字符后是否还有字符
                if(res[j+2]){
                    //存在且是第三个连续字符
                    if(res[j+2]==res[j]){
                        result=result+res[j]*3;
                        j=j+2;//跳过连续字符
                    }
                    //存在但不是连续字符且符合罗马数字格式
                    else if(res[j+2]!=res[j]&&(res[j+2]<res[j])){
                        result=result+res[j]*2;
                        j=j+1;//跳过连续字符
                    }
                    //存在但不是连续字符也不符合罗马数字格式,例：IIVI,歧义（1+4+1）（1+1+5+1）
                    else{
                        return '格式不合法';
                    }
                }
                //连续字符后没有字符了
                else{
                    result=result+res[j]*2;
                    return result;
                }
                continue;
            }
            //是可以连续的字符，但不能满足最小连续字符长度2.
            else if(!res[j+1]){
                result+=res[j];
                return result
            }
            else{
                return '格式不合法';
            }
        }
        return result;
     }
     else{
         return '格式不合法'
     }
```

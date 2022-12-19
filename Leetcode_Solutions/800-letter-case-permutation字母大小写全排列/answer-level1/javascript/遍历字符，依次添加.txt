### 解题思路
按照字母顺序，依次添加，以'a1b2'为例：
1.a A
2.a1 A1
3.a1b a1B A1b A1B
4.a1b2 a1B2 A1b2 A1B2

### 代码

```javascript
/**
 * @param {string} S
 * @return {string[]}
 */
var letterCasePermutation = function (S) {
            let str = S.split("");
            let res = [];//保存结果的数组
            for (let i = 0; i < str.length; i++) {
                let s  = str[i]
                let code = s.charCodeAt()//
                if (code >= 65 && code <= 90 || code >= 97 && code <= 122) {//如果是字母
                    if (res.length) {
                        for (let i = 0; i < res.length; i += 2) {                            
                            res.splice(i,0,res[i])//复制一份
                            res[i] += s.toLowerCase()//添加一个小写字母
                            res[i+1] += s.toUpperCase()//添加一个大写字母
                        }
                    }else{//首个字符为字母时，添加其大写和小写两个字母
                        res.push(s.toLowerCase())
                        res.push(s.toUpperCase())
                    }
                } else {
                    if(res.length){//数字，则所有项都直接添加
                        for(let index in res){
                            res[index] += s
                        }
                    }else{//首字符为数字时
                        res.push(s)
                    }
                }
            }
            return res
        };
```
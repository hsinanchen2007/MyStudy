第一次超过100%，小小记录下，虽然是直接用了原生的翻转方法![微信图片_20191118135926.png](https://pic.leetcode-cn.com/cce597d704bd622407ab7c4950386d8b54ec4def99d4719676d2c87807cf4cd6-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20191118135926.png)  

```
var reverseWords = function(s) {
    let temp = s.split(' '),result=[];
    for(let i=0;i<temp.length;i++){
      if(temp[i].length != '')
      {
        result.push(temp[i]);
      }
    }
    result.reverse();
    console.log(result.join(' '));
    return result.join(' ');
};
```


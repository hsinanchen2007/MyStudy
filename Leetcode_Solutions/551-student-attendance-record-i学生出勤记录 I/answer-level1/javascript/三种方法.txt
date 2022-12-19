### 解题思路
方法一、两次遍历，分别统计'A'的个数，连续'L'的个数

### 代码

```javascript
/**
 * @param {string} s
 * @return {boolean}
 */
var checkRecord = function(s) {
    var countA=0;  
    for(var i=0;i<s.length;i++){
        
        if(s[i]=='A'){
            countA++;
        }
        if(countA>1)return false;
    }
    for(var i=0;i<s.length;i++){
        var countL=0;
        while(s[i]=='L'){
            countL++;
            i++;
        }
        if(countL>2){return false;}
    }
    return true;
};
```
方法二、数组前后各插入一个’P‘
```
var checkRecord = function(s) {
    var countA=0;
    var countL=0;
    var arr=s.split('');
    arr.push('P');
    arr.unshift('P')
    for(var i=1;i<arr.length-1;i++){
        if(arr[i]=='A'){
            countA++;
            if(countA>1)return false;
        }
        if(arr[i]=='L'&&arr[i-1]=='L'&&arr[i+1]=='L'){
            return false;
        }
    }
    return true;
};
```
方法三、确保在进行连续的 ’L‘出现之前，countL 的值为0
```
var checkRecord = function(s) {
    var countA=0;
    var countL=0;
    for(var i=0;i<s.length;i++){
        if(s[i]=='P'){
            countL=0;
        }else{
            if(s[i]=='A'){
                countA++;
                if(countA>1)return false;
                countL=0;
            }else if(s[i]=='L'){
                countL++;
                if(countL>2)return false;
                }
    }
    }
    return true;
};

```


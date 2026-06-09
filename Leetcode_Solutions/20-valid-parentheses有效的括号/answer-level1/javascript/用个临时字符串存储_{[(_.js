### 解题思路
先判断特殊情况，奇数，空，等。
再弄一个临时字符串存存"{[(",遇到闭合括号时必定和临时字符串的最后一个闭合，否则返回false，遇到正常闭合就把临时字符串的最后一个删除。
遇到"{[("时就添加进临时字符串，遇到正常闭合时就删去临时字符串的最后一个。
执行完毕如果临时字符串为空，则代表全部正常闭合。

### 代码

```javascript
/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function(s) {
     let tmpStr = "";

    	if(s.length == 0){
    		return true;
    	}else if(s.length == 1){
   	 		return false;
   	 	}else if( s.length%2 != 0){
   	 	    return false;
   	 	}


    for (var i = 0; i <= s.length-1; i++) {
    	//和最后一个朝右开口闭合
    	if(s.charAt(i) == '}'){
    		if(tmpStr.charAt(tmpStr.length-1) == "{"){
    			// 删除临时字符串的最后一个
    			tmpStr = tmpStr.substring(0,tmpStr.length-1);
    		}else{
    			return false;
    		}
    	} else if(s.charAt(i) == ']'){
    		if(tmpStr.charAt(tmpStr.length-1) == "["){
    			// 删除临时字符串的最后一个
    			tmpStr = tmpStr.substring(0,tmpStr.length-1);
    		}else{
    			return false;
    		}
    	}else if(s.charAt(i) == ')'){
    		if(tmpStr.charAt(tmpStr.length-1) == "("){
    			// 删除临时字符串的最后一个
    			tmpStr = tmpStr.substring(0,tmpStr.length-1);
    		}else{
    			return false;
    		}
    	}
    	else{
    		tmpStr += s.charAt(i);
    	}
   	 	
    }


    if(tmpStr.length == 0){
    	return true;
    }else{
    	return false;
    }

};
```
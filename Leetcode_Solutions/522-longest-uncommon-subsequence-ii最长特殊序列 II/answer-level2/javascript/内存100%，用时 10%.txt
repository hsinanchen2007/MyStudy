```
/**
 * @param {string[]} strs
 * @return {number}
 */
var findLUSlength = function(strs) {
//找到不重复且不是别人子串的字符串，取最大长度即可。
    //长度从到小排序
    strs.sort((a,b)=>b.length-a.length);
    for(var i=0;i<strs.length;i++){
        if(subStr(strs,i)){
            return strs[i].length;
        }
    }
    return -1;

    //判断当前位置的字符串是否只有一个，并且不是其他字符串的子串
    function subStr(arr,i){
        var flag;
        if(arr.indexOf(arr[i]) == arr.lastIndexOf(arr[i])){
            flag=true;
        }else{
            flag=false;
        }
        for(var j=0;j<i;j++){
            //判断当前字符串arr[i]是不是前面比他长的字符串arr[j]的子串
            if(valid(arr[j],arr[i]))return false;
        }
        return flag;
    }

    //验证一个字符串是不是另一个字符串的子串
    function valid(a,b){
        //indexOf方法只能检测字符串是否是另一个字符串的连续子串
        // 比如 helloworld  和  world
        if(a.indexOf(b)!=-1) return true; 
 
        //在本题中 helloworld  和 hllrd 也是它的子串
        var i=0,j=0;
        while(i<a.length){
            if(a.charAt(i) == b.charAt(j)){
                j++;
                if(j==b.length)return true;
            }
            i++;
        }
        return false;
    }
};
```

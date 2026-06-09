```
/**
 * @param {string} s
 * @return {string}
 */
	var longestPalindrome = function(s) {
	
        if(s.length<2) return s;
        //不管是双核还是单核，都转化成单核         
        let arr=[];
        for(let i=0;i<s.length;i++){
            arr.push(s[i]);
            arr.push("#");
        }
        s=arr;
        s.unshift("#");
        
        //中心对称方式查找
        let max='';
        let len=s.length;
        for(let i=0;i<len;i++){
            let str=core(s,i-1,i+1);
            if(max.length<str.length){
                max=str
            }     
        }
        //实现中心对称查找
        function core(s,l,r) {
            while (s[l]&&s[r] && s[l]==s[r]){
                l=l-1;
                r=r+1;
            }
            return s.slice(l+1,r);
        }
        //去除附加字符后的结果返回
        return max.join("#").replace(/#/g,"");

	};
```

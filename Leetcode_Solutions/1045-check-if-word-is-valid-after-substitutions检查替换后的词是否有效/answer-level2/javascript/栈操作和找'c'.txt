看到js栏没人解题，那就小试牛刀一下。
我的思路是，遍历一遍S，遇到一个字符，就放入栈中。
当遇到'c'时，判断栈的后两位是否分别为'b'和'a'（顺序也一致）如果不是，那肯定无效。

当遍历完所有字符串后，栈内空了，则证明abc都用上

此处优化点：
`let count = S.length; 和 if(count%3){return false;}`
以上两点可以减少一些运算

```
var isValid = function(S) {
	let count = S.length;
	if(count%3){
		return false;
	}
	let strArr = [];
	for(let i =0;i<count;i++){
		if(S[i]==='c'){
			if(strArr[strArr.length-1]==='b'&&strArr[strArr.length-2]==='a'){
				strArr.splice(-2)
			}else{
				return false;
			}
		}else{
			strArr.push(S[i])
		}
	}
	return !strArr.length;
};
```

其实刚开始可以做发散，有关子串不规定长度，结果如其他解法一样，当遇到 s="ababaab",words=["ab","ba","ba"]的情况时就会出现重复单词查找，导致结果不匹配，“babaab”这个串被解析为“b,ab,a,ab”,这又涉及到words组合排序的问题，所以为了简化难度，将words的单位长度固定，“babaab”被解析为“ba，ba，ab”，由此可得基础算法；


```javascript []
function findSubstring(s,words){
	let len=0;
	let le=0;
	for(let i in list){
		len+=list[i].length;
		le=list[i].length;
	}
	let rst=[];
	let stMap={};
	for(let i in list){
		if(!stMap[list[i]]){
			stMap[list[i]]=1;
		}else {
			stMap[list[i]]+=1;
		}
	}
	for(let i=0;i<=str.length-len;i++){
		let st=str.substr(i,len);
		let exist=true;
		let smap={};
		for(let i=0;i<len;i+=le){
			let s=st.substr(i,le);
			if(!smap[s]){
				smap[s]=0;
			}
			smap[s]+=1;
		}
		let e=0;
		for(let k in smap){
			if(stMap[k]&&smap[k]==stMap[k]){
				e+=1;
			}else {
				exist=false;
				break;
			}
		}
		if(!exist||e==0){
			continue;
		}
		rst.push(i);
	}
	return rst;
}
```
上面的代码由于js对象创建较多，导致在大量数据运算时，消耗内存严重，由此可简化对象创建的次数，用属性初始化指针代替：

```javascript []
var findSubstring = function(s, words) {
    let len;
    if(words.length>0){
        len=words[0].length;
    }
  
    return   existsStr(s,words,len);
};
function initListMap(list){
	let map={};
	for(let i of list){
		if(!map[i]){
			map[i]={start:0};
		}
		map[i].start+=1;
	}
	return map;
}
function formateListMap(map){
	for(let i in map){
		map[i]["exist"]=map[i].start;
	}
}
function existsStr(str,list,len){
	let rst=[];
	if(len){
		let long=len*list.length;
		let listMap=initListMap(list);
		for(let i=0;i+long<=str.length;i++){
			let st=str.substr(i,long);
			formateListMap(listMap);
			let exist=true;
			for(let k=0;k<long;k+=len){
				let s=st.substr(k,len);
				if(listMap[s]&&listMap[s].exist>0){
					listMap[s].exist=listMap[s].exist-1;
				}else {
					exist=false;
					break;
				}
			}
			if(!exist){
				continue;
			}
			rst.push(i);
		}
	}
	return rst;
}
```
变化在于map在重复调用的时候重置属性，并没有重复创建大量的相似对象，极大降低对内存的消耗，其实操作由于其重复性可简化为递归算法，但是大数据可能导致栈溢出，在此不做推荐
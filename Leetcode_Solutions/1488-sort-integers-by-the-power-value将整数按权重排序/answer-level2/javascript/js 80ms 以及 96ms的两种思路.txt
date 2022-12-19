# 96ms 思路 :

这个思路分成两个步骤：
步骤1.递归求出当前元素的权重。在求权重的过程中进行记录。
步骤2.二分插入排序

## 步骤1.递归 + 记忆法求权重。
```
var map  = {};

var getHeight = function(n){
	var res = "";
	if(map[n]){
		return map[n];
	}
   var base2 = getBase(n);
   if(base2%1 === 0 ){
   	 map[n] = base2
   	 return  map[n];
   }
   var next = n % 2 === 0 ? n/2: 3 * n + 1;
   map[n] = 1 + getHeight(next);
   return map[n] ;
}

var getBase = function(k){
	return Math.log(k) / Math.log(2);
}
```

## 步骤2.二分插入排序：

如果当前元素大于当前排序数组的第K个元素，则抛弃。
如果当前元素小于当前排序数组的第K个严肃，则进行二分插入。

```

var insetSort = function(lists,curEle,start,end){
	if(lists.length===0){
		lists.push(curEle);
		return;
	}
	var itemStart = lists[start];
	var itemEnd = lists[end];
	var middleIndex = (start + end) % 2 === 0 ?(start + end) / 2 : (start + end + 1) / 2  ;
	var itemMiddle = lists[middleIndex];
	if(start >= end ){
		if(curEle.curHei<itemStart.curHei || (curEle.curHei == itemStart.curHei && curEle.val<=itemStart.val)){
			if(start == 0 ){
				lists.unshift(curEle);
				return;
			}
			lists.splice(start-1,0,curEle)
			return;
		}else{
			lists.splice(start+1,0,curEle)
			return;
		}
	}
	if(curEle.curHei<itemStart.curHei || (curEle.curHei == itemStart.curHei && curEle.val<=itemStart.val)){
		if(start == 0 ){
			lists.unshift(curEle);
			return;
		}
		lists.splice(start-1,0,curEle)
		return;
	}
	if(curEle.curHei>itemEnd.curHei || (curEle.curHei == itemEnd.curHei && curEle.val>=itemEnd.val)){
		lists.splice(end + 1,0,curEle);
		return;
	}
	if(curEle.curHei == itemMiddle.curHei && curEle.curHei.val ==  itemMiddle.val){
		lists.splice(middleIndex + 1,0,curEle);
		return;
	}
	
	if(curEle.curHei < itemMiddle.curHei || (curEle.curHei == itemMiddle.curHei)&& curEle.val < itemMiddle.val){
		 insetSort(lists,curEle,start,middleIndex -1);
	}else{
		insetSort(lists,curEle,middleIndex ,end);
	}

}
```
## 主程序
```
var getKth = function(lo, hi, k) {
	var curHei = "";
	var lists = [];
	var insertStart = 0;
	var insetEnd = 0;
	var curEle = {};
	if(lo === hi && k === 1){
		return lo;
	}
	for(var i= lo;i<= hi;i++){
		curHei = getHeight(i);
		if(lists.length > k && (curHei>lists[k].curHei || (curHei === lists[k].curHei && i >= lists[k].val))){
			continue;
		}
		insetEnd = lists.length -1;
		curEle = {
			val: i,
			curHei : curHei
		}
		insetSort(lists,curEle,insertStart,insetEnd);
	}
	return lists[k-1].val;
};
```

缺点：二分插入代码量特别多，在面试的时候很不利。于是就有第二种更省时省力的高兴能思路。

# 80ms 思路 :

这个思路与上面第一个思路的主要区别在于步骤2.
步骤1.递归 + 记忆法求权重
步骤2.、根据权重进行查找第K个元素

## 步骤1.递归 + 记忆法求权重
```
let map  = {};

var getHeight = function(n){
	var res = "";
	if(map[n]){
		return map[n];
	}
   var base2 = getBase(n);
   if(base2%1 === 0 ){
   	 map[n] = base2
   	 return  map[n];
   }
   var next = n % 2 === 0 ? n/2: 3 * n + 1;
   map[n] = 1 + getHeight(next);
   return map[n] ;
}

var getBase = function(k){
	return Math.log(k) / Math.log(2);
}
```

## 根据权重进行查找第K个元素

```
 for(var i in resMap){
    if(curNum + resMap[i].length >= k){
        var index = k - curNum - 1;
        return resMap[i][index]
    }

    if( curNum + resMap[i].length < k){
        curNum += resMap[i].length;
    }

}
```

## 主程序
```
var getKth = function(lo, hi, k) {
	var curHei = "";
	var lists = [];
	var insertStart = 0;
	var insetEnd = 0;
	var curEle = {};
    var resMap = {};
    var curNum = 0;
	if(lo === hi && k === 1){
		return lo;
	}
	for(var i= lo;i<= hi;i++){
		curHei = getHeight(i);
		if(resMap[curHei] == undefined){
            resMap[curHei] = [];
        }
        resMap[curHei].push(i);
	}
   for(var i in resMap){
       if(curNum + resMap[i].length >= k){
           var index = k - curNum - 1;
           return resMap[i][index]
       }

       if( curNum + resMap[i].length < k){
           curNum += resMap[i].length;
       }

   }
	
};
```



# 80ms 的全部代码
```
var getKth = function(lo, hi, k) {
	var curHei = "";
	var lists = [];
	var insertStart = 0;
	var insetEnd = 0;
	var curEle = {};
    var resMap = {};
    var curNum = 0;
	if(lo === hi && k === 1){
		return lo;
	}
	for(var i= lo;i<= hi;i++){
		curHei = getHeight(i);
		if(resMap[curHei] == undefined){
            resMap[curHei] = [];
        }
        resMap[curHei].push(i);
	}
   for(var i in resMap){
       if(curNum + resMap[i].length >= k){
           var index = k - curNum - 1;
           return resMap[i][index]
       }

       if( curNum + resMap[i].length < k){
           curNum += resMap[i].length;
       }

   }
	
};

let map  = {};

var getHeight = function(n){
	var res = "";
	if(map[n]){
		return map[n];
	}
   var base2 = getBase(n);
   if(base2%1 === 0 ){
   	 map[n] = base2
   	 return  map[n];
   }
   var next = n % 2 === 0 ? n/2: 3 * n + 1;
   map[n] = 1 + getHeight(next);
   return map[n] ;
}

var getBase = function(k){
	return Math.log(k) / Math.log(2);
}
```

# 解法亮点
## 亮点1.递归结束条件并非1，而是2的幂数。
2的幂数 可以直接通过求对数来直接计算结果，不需要继续递归计算。
##  亮点1.存储的时候，按权重归类。
利用js特性：哈希表在 for in 遍历的时候，会默认从小到大进行遍历，所以权重无需排序。
map : {
  1 : [],
  ...
  n : []
}
插入的时候 map[height] = val。map 会自动进行排序
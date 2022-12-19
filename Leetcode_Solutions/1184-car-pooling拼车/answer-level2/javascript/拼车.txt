### 解题思路
![111.PNG](https://pic.leetcode-cn.com/a1ab6d27f749d0d219bf5f137530eaa21d6d678885f533dd15641816dc98aba2-111.PNG)

1.数组的运用，for循环，while循环，if语句
2.将每个地点的数组信息重新拆分为三个数组，分别记录乘客的数量，乘客乘车的地点，乘客下车的地点
3.求出最大距离，方便循环控制人数的增减（即上下车）距离增加 1 时，循环判断乘客上下车的数组是否需要上车或下车
4.注意上下车时不能改变第 2 步中生成的是三个数组，因此只能每次判断重新赋值给新变量，并且为了控制各个数组下标相同，
不能删除重新赋值生成的那个数组中的元素，只能找到不影响数据的元素进行替换，比如 ‘’（空字符）
5.如果车上人的数量大于capacity 或者小于0，均返回 false,否则返回 true

### 代码

```javascript
/**
 * @param {number[][]} trips
 * @param {number} capacity
 * @return {boolean}
 */
var carPooling = function(trips, capacity) {
 	var str_start=[];           //记录整个记录的开始数组，与原来的数组的下标相对应
	var str_end=[];             //记录整个记录的结束数组，与原来的数组的下标相对应
	var str_num=[];             //记录每个地点上车乘客的数量
	var p_num=0;        //记录乘客数量
	for(let i=0;i<trips.length;i++){     
		str_num.push(trips[i][0]);
		str_start.push(trips[i][1]);
		str_end.push(trips[i][2]);
	}

	var dis_max=trips[0][2];      //记录最大距离
	for(let i=0;i<trips.length;i++){     
		if(dis_max<trips[i][2]){
			dis_max=trips[i][2];
		}
	}

	for(var i=1;i<=dis_max;i++){                             //乘车假定都为先下后上
		var str_end_1=[...str_end];                           //数组复制
		while(str_end_1.indexOf(i)!==-1){                         //下车
			p_num=p_num-str_num[str_end_1.indexOf(i)];
			str_end_1[str_end_1.indexOf(i)]='';
		};
		if(p_num<0){
			return(false);
		}

		var str_start_1=[...str_start];                           //数组复制
		while(str_start_1.indexOf(i)!==-1){                              //上车
			p_num=p_num+str_num[str_start_1.indexOf(i)];
			str_start_1[str_start_1.indexOf(i)]='';
		}
		if(p_num>capacity){
			return(false);
		}
	}
	return(true);
};
```
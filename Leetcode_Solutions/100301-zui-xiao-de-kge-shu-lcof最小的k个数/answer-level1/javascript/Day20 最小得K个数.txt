### 解题思路
本题关键在于先排序，然后取出k个虽小的数：arr.slice(0,k);
方法一：最简单的方法：
使用array自带得方法按升序排列
然后取出前k个数
```
var getLeastNumbers = function(arr, k) {
    arr.sort(function compare(a,b){
		return a-b;
	});
		return arr.slice(0,k);
};
```
方法二：快速排序
关键，排序：由于数组没有什么特殊性，所以要想排序的事件复杂度低，可以选择快速排序、归并排序、或者堆排序。在这里选择快速排序

快速排序相比第一种方法执行勇士提高了60ms

### 代码

```javascript
/**
 * @param {number[]} arr
 * @param {number} k
 * @return {number[]}
 */
var getLeastNumbers = function(arr, k) {
            quickSort(arr,0,arr.length-1);
			return arr.slice(0,k);
			function quickSort(arr,L,R){
				if(arr==null||arr.length<2){
					return;
				}
				//在L--R上排好序
				if(L<R){
					//等概率选择数组中的任意一个数作为初始比较值
					var p1 = Math.floor(Math.random()*(R-L));
					swap(arr,L+p1,R);
					var p = partition(arr,L,R);
					quickSort(arr,L,p[0]-1);
					quickSort(arr,p[1]+1,R);
				}
				return arr;
			}
			function partition(arr,L,R){
				var less = L-1;
				var more = R;
				while(L<more){
					if(arr[L]<arr[R]){
						swap(arr,++less,L++);
					}else if(arr[L]>arr[R]){
						swap(arr,--more,L);
					}else{
						L++;
					}
				}
				swap(arr,more,R);
				return [less+1,more];
			}
			function swap(arr,i,j){
				var temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
};
```
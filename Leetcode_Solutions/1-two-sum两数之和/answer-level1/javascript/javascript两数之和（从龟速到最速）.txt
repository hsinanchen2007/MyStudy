很少看到有关于javascript的详细解决方法，我决定把自己想到的方法都写出来，欢迎大家来参考以及指正
### 方法 1 暴力双for循环 #
用两个for循环来进行操作，优点是如果没接触过的话可能第一时间想到用这个方法，缺点是耗时太长，而且时间复杂度为O(n^2），不推荐使用

```js
	var twoSum = function(nums, target) {
                    let arr = nums;
                    let arrs = new Array()
                    for(let i =  0; i < arr.length - 1; i++){
                        for(let j = 0; j < arr.length; j++){
                            if ( arr[i] + arr[j] === target) {
                                arrs.push(i, j)
                                return arrs
                            }
                        }
                    }
                }
```

### 方法 2 使用Map函数 #
创建一个Map()，将要比较的数组中每个数所在的位置和数用Map数据结构存储起来，然后使用for循环来和map里面的数据进行比较，这里要注意一下，因为不能重复使用数组里面位置相同的数字，必须要对比一下map里面存储的位置与当前比较的数字的位置是否相同

```js
	var twoSum = function(nums, target) {
	    let map = new Map();
	    let arr = new Array()
	    for(let i in nums){
	        map.set(
	            nums[i],
	            i
	        )
	    }
	    
	    for(let j = 0; j < nums.length - 1; j++){
	        if(map.has( target - nums[j] ) && map.get( target - nums[j]) != j ){
	            arr.push( j , map.get( target - nums[j] ) );
	            return arr
	        }
	    }
    
	}
```

###  方法 3 边存边比较 #
非常简洁的一个方法，原理是先创建一个json空数组，以键值对的方式存储位置和对应的数字，然后for循环给的数组，当前数字不符合要求就存入json，然后再次比较，直到得到正确答案

```js
	var twoSum = function(nums, target) {
	   const map = {}
	   for (let i = 0; i < nums.length; i++){
	       if(map[target - nums[i] ] >= 0){
	           return [ map[target - nums[i] ], i]
	       }
	       map[nums[i]] = i;            
	    }
    
	}
```

### 方法 3.5 将方法3改成尾递归的形势 #
执行速度比方法3快了40ms左右，记得使用尾递归优化

```js
	var twoSum = function(nums, target, i = 0, maps = {}) {
	    const map = maps
	        if(map[target - nums[i] ] >= 0 ) {
	            return [ map[target - nums[i] ], i]
	        } else {
	            map[ nums[i] ] = i;
	            i++;
	            if(i < nums.length - 1){
	                return twoSum(nums, target, i, map)
	            }else {
	                throw 'error: twoSum is not find'
	            }
	            
	            
	        }
	}
```

结语：这 4 个方法中 3.5 的速度是最快的，76ms，击败了99.19%的用户，内存占用为35.6MB，我有一个疑问，怎么样才能在不损失执行速度的情况下如何将内存消耗进一步降下去，欢迎大家在评论区中指点
### 解题思路
1. 解法一，两次循环，首次记录并填充非零数据，二次循环补零
2. 解法二，一次循环，非零左移，零右移
3. 解法三，一次循环，填充非零元素的同时进行补零

### 解法一


```javascript

var moveZeroes = function(nums) {
  let j=0;

  for(let i=0;i<nums.length;i++){

      if(nums[i]!==0){
         nums[j++]=nums[i];
      }
  }

  for(let i=j;i<nums.length;i++){
      nums[i]=0;
  }


};



```

### 解法二

```javascript
var moveZeroes = function(nums) {

 
  let j=0;

  for(let i=0;i<nums.length;i++){

      if(nums[i]!==0){
        
        [ nums[i] , nums[j]]= [nums[j] , nums[i]]
       
          j++;
      }
  }


};


```

### 解法三



```javascript
var moveZeroes = function(nums) {

 
  let j=0;

  for(let i=0;i<nums.length;i++){

      if(nums[i]!==0){
        nums[j]=nums[i];

      //这里i,j不相等说明一定有0存在
        if(i!==j){
          nums[i]=0;
        }
        j++;

      }
  }


};


```
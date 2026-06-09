### 解题思路

执行用时 :92 ms, 在所有 JavaScript 提交中击败了97.66%的用户
内存消耗 :41.7 MB, 在所有 JavaScript 提交中击败了100.00%的用户
### 代码

```javascript
var maxSlidingWindow = function(nums, k) {
 
    // var win = nums.slice(0,k);
     var max = [];//最大值存储的的数组
     if(nums.length == 0){return max;}
     if(k > nums.length){return max;}
     var maxNumInMax =1;//最大值在最大值数组里的个数
     var maxCurr = nums[0]; //当前的最大值
     //初始化第一个窗口
     for(let i = 1; i < k; i++){
         if(nums[i] > maxCurr){
         maxCurr=nums[i];
         maxNumInMax=1;
         }
         else if(nums[i]==maxCurr){
             maxNumInMax++;
         }
     }
     max.push(maxCurr);
 
     //开始滑动
     for (let j = k; j < nums.length; j++){
        //  console.log('-------');
        //  console.log("j :",j);
 
        //  console.log("max :",max);
        //  console.log("maxCurr:",maxCurr);
        //  console.log("maxNumInMax",maxNumInMax)
         //nums[j]是新加入的，nums[j-k]是退出的
         if(nums[j] > maxCurr){//加入的大，就不用管现有的
           //  console.log("nums[j] > maxCurr")
             maxCurr = nums[j];
             maxNumInMax=1;//重新计数
             max.push(maxCurr);
         }else if(nums[j]==maxCurr){//加入的等于最大值，就看退出的是不是和最大值有关。
              //console.log("nums[j] == maxCurr")
             if(nums[j-k]!==maxCurr){
                 maxNumInMax++;
             }
             max.push(nums[j]);
         }else if(nums[j] < maxCurr){//加入的小，
          //console.log("nums[j] < maxCurr")
             if(nums[j-k]==maxCurr){//退出的等于最大值
                 if(maxNumInMax > 1){//有另一个最大值
                     maxNumInMax--;
                     max.push(maxCurr);
                 }
                 else{//需要重新计算最大值
                     maxCurr=nums[j-k+1];
                     maxNumInMax=1;
                     for(let i = j-k+2; i<=j;i++){
                         if(nums[i] > maxCurr){
                             maxCurr=nums[i];
                             maxNumInMax=1;
                         }
                         else if(nums[i]==maxCurr){
                             maxNumInMax++;
                         }
                     }
                     max.push(maxCurr);
                 }
             }
             else{max.push(maxCurr);}
         }
     }
     return max;
     
 };

//  var nums=[9,10,9,-7,-4,-8,2,-6];
//  var k=5;
//  console.log("res:",maxSlidingWindow(nums,k))
//输入
//[1,3,1,2,0,5]
//3

//预期结果
//[3,3,2,5]???
```
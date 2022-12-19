let ans = nums[0];
      let sum = 0;
      for(let num of nums){
          if(sum > 0){
              sum += num;
          }else{
              sum = num
          }
          ans = Math.max(sum,ans)
      }
      return ans;
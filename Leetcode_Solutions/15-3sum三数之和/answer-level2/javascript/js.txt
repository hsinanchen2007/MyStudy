var threeSum = function(nums) {
    let result=new Array();
    let start;
    let end;
    let fixedval;
    nums.sort(function (a,b) {
      return a-b;
    })
    //判断数组内元素是否都为整数或负数，直接返回
    if(nums[0]>0||nums[nums.length-1]<0){
      return result;
    }
        //遍历
    for(let i=0;i<nums.length;i++){
      fixedval=nums[i];
      if(fixedval === nums[i-1]) continue;
      //一开始的固定值为nums[0],所以头指针为 i+1 下一个元素
      start=i+1;
      //尾指针
      end=nums.length-1;
      //如果头指针小于尾指针
      while(start<end){
        if(nums[start] + nums[end] + fixedval === 0){
          let group=new Array();
          group.push(nums[start]);
            group.push(nums[end]);
            group.push(fixedval);
            result.push(group);
          //存放完毕之后，不要忘记头指针和尾指针的移动(否则会产生死循环)
          start+=1;
          end-=1;
          //如果头指针满足小于尾指针且移动后的指针和移动前的指针元素相等，再往前移动
         while(start < end && nums[start] === nums[start - 1]){
                    start += 1;
                }
                 //如果头指针满足小于尾指针且移动后的指针和移动前的指针元素相等，再往后移动
                while(start < end && nums[end] === nums[end + 1]){
                    end -= 1;
                }
        }else if(nums[start] + nums[end] + fixedval < 0){
                start++;
            }else{
                //否则，尾指针向前移动，让数据小于元数据
                end--;
            }
      }
    }
    return result;
    }
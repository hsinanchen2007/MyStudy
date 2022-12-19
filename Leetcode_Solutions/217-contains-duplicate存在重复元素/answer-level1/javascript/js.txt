 推荐Set方法，利用了Set方法去重的原理
    return new Set(nums).size < nums.length;
 排序法
    nums.sort()
    for(let i=0;i<nums.length;i++){
        if(nums[i]==nums[i+1]){
            return true
        }
    }
    return false
  粗暴的一种不可取的方法，耗时2000+ms 
    var arr=[]
    for(let i=0;i<nums.length;i++){
        if(arr.indexOf(nums[i])==-1){
            arr.push(nums[i])
        }else{
            return true
        }
    }
    return false
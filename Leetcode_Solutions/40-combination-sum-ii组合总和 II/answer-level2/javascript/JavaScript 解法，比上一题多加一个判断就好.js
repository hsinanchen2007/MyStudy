```
var combinationSum2 = function(candidates, target) {
    candidates.sort((a,b)=>{return b-a})
  
   let len =  candidates.length
   let min = candidates[len-1];
   let res=[];
   let path =[];
  
  function combin(candidates,target,i,path) {
      if(target == 0){
          return res.push(path.slice())
      }
      
      if(target < min){
          return;
      }
      
      for(let start =i;start < len ;start++){
          if (candidates[start] === candidates[start-1] && start > i) continue;
          path.push(candidates[start])
          combin(candidates,target-candidates[start],start+1,path)
          path.pop()
      }
  }
    
    combin(candidates,target,0,path);
    
    return res;
};

比上一题多加一个判断
if (candidates[start] === candidates[start-1] && start > i) continue;
如果两个一样的数字，只要走前一个就好

```

```
var gardenNoAdj = function(N, paths) {
    
    // 利用对象存储每个花园对应的相连花园
    const gardenObj = {};
    paths.forEach((item)=>{
        const [firstNum, lastNum] = item;
        if(gardenObj[firstNum]){
            gardenObj[firstNum].push(lastNum);
        }else{
            gardenObj[firstNum] = [lastNum];
        }
        
        if(gardenObj[lastNum] && gardenObj[lastNum] !== firstNum){
            gardenObj[lastNum].push(firstNum);
        }else if(!gardenObj[lastNum]){
            gardenObj[lastNum] = [firstNum];
        }
    });
    // 为每一个花园选择种的花的种类
    const answer = [];
    for(var i=0; i<N; i++){
        const garden = i + 1;
        const currentRelate = gardenObj[garden];
        if(!currentRelate){
            const flower = Math.ceil(Math.random()*4);
            answer.push(flower);
            continue;
        }
        
        for(var j = 1; j <= 4; j++){
            // 遍历关系花园，判断是否存在相等的种类
            const flag = currentRelate.find((item)=>{
                if(answer[item-1] && answer[item-1] === j){
                    return true;
                } 
            }); 
            if(flag){
                continue;
            }else{
                answer.push(j);
                break;
            }
        }
    }
    return answer;
};
```

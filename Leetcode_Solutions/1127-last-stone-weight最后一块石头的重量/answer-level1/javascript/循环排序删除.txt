1.将石头重量排序
2.最大的减去次大石头的重量
3.最大和次大同重则数组中删除2个
4.重新排序，直至数组长度小于1
var lastStoneWeight = function(stones) {
    stones.sort((a,b)=>b-a)
    while(stones.length>1){
        stones[0]-=stones[1];//最大
        stones[1]=0;//次大
        if(stones[0]==stones[1]){
            stones.splice(0,2);
        }else{
            stones.splice(1,1);
        }
        stones.sort((a,b)=>b-a)
    }
   if(stones.length>0){
       return stones[0];
   }else{
       return 0;
   }
};
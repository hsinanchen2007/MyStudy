```
/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var permuteUnique = function(nums) {
    nums.sort((a,b)=>a-b);
    let temp = [],list=[];
    let one = (list,who,start)=>{
        if(list.length == nums.length){
            temp.push(list);
            return;
        }

        for(let i=0;i<who.length;i++){
            if(start.indexOf(i)<0){
                list.push(who[i]);
                start.push(i);
                one(list.slice(),who,start);
                start.pop();
                list.pop();
                while(who[i+1] == who[i]){
                    i++;
                }
            }
        }
    }

    one(list,nums.slice(),[]);
    return temp;
};
```

